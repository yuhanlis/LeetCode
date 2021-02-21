#include <stdio.h>
#include <cstring>
#include <string>
#include <ctype.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <queue>
#include <sstream>
#include <thread>
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  /*初始化互斥锁*/

const int MAXLINE = 80;
const int SERV_PORT = 8000;
const int MAXPTHREAD =100;
const int MAXMSG = 20;
const unsigned int Read = 0;
const unsigned int Write = 1;

/*总线程数以及完成接口判断的线程数*/
int pthread_num = 0;                     
int depthread_num = 0;

struct s_info                                       /*客户端套接字结构体*/
{
	struct sockaddr_in cliaddr;
	int connfd;
};

queue<string> Msg;    /*定义消息队列*/

/*************************************************
  * Function:       rec_msg()
  * Description:    处理标准输入并将标准输入压入消息队列
  * Input:          N/A
  * Output:         N/A
  * Return:         N/A
*************************************************/

void* rec_msg(void* arg)
{
	char buf[MAXLINE];
	while(1)
	{
		if(NULL != fgets(buf,MAXLINE,stdin))
		{
			pthread_mutex_lock(&mutex);
			string client_msg=buf;
			if(Msg.size()<=MAXMSG)
			{
				Msg.push(client_msg);
			}
			pthread_mutex_unlock(&mutex);
		}
	}
}

/*************************************************
  * Function:       do_work()
  * Description:    与客户端通信的工作线程
  * Input:          s_info结构体
  * Output:         N/A
  * Return:         N/A
*************************************************/
void* do_work(void* arg)
{
	int flag_rw=0;
	struct s_info* ts = (struct s_info*)arg;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];

	pthread_detach(pthread_self());

	while(1)
	{
		if(Read == flag_rw)
		{
			//读取客户端数据并回复
			int ret = read(ts->connfd, buf, MAXLINE);
			if(0 == ret)
			{
				cout<<"the Client "<<ntohs((*ts).cliaddr.sin_port)<<" side has been closed !"<<endl;
				break;
			}
			else if(strcmp(buf,"over\n") == 0)
			{
				flag_rw = Write;
				cout<<"Switch wirte mode!"<<endl;
			}
			else
			{
				cout<<"received from"<<inet_ntop(AF_INET, &(*ts).cliaddr.sin_addr, str, sizeof(str))<<" at Port "<<ntohs((*ts).cliaddr.sin_port)<<":"<<endl;
				write(STDOUT_FILENO, buf, ret);
			}
			bzero(&buf, sizeof(buf));
		}
		if(Write == flag_rw)
		{
			//向客户端发送数据
			pthread_mutex_lock(&mutex);
			if(!Msg.empty())
			{
				string temp = Msg.front();
				size_t found =temp.find_first_of(':');

				if(string::npos != found)				/*寻找消息中是否有‘：’*/
				{
					temp.erase(found,(temp.size()-found));
					stringstream temp_2;
					temp_2<<ntohs((*ts).cliaddr.sin_port);

					if(temp == temp_2.str())			/*判断当前线程端口是否与消息中的端口相同*/
					{
						temp = Msg.front();
						temp.erase(0,found+1);
						write(ts->connfd, temp.c_str(), temp.size());
						Msg.pop();

						if(strcmp(temp.c_str(),"over\n") == 0)
						{
							flag_rw = Read;
							cout<<"Switch read mode!"<<endl;
						}
						else if(strcmp(temp.c_str(),"quit\n") == 0)
						{
							cout<<"closed connect"<<endl;
							break;
						}
					}
					else
					{
						depthread_num++;
						if(depthread_num == pthread_num)
						{
							Msg.pop();
							depthread_num = 0;
						}
					}
				
				}
				else
				{
					Msg.pop();
					cout<<"server not input  correct message format!"<<endl;
				}
			}
			pthread_mutex_unlock(&mutex);
		}
	}
	close(ts->connfd);
}

int main()
{

	pthread_t tid[MAXPTHREAD],msg_tid;
	
	int listenfd = 0;
	int connfd = 0;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int i=0;
	
	struct s_info ts[MAXPTHREAD];

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr =inet_addr("127.0.0.1");			/*设置IP*/
	servaddr.sin_port = htons(SERV_PORT);						/*设置端口*/

	bind(listenfd, (struct sockaddr* )&servaddr, sizeof(servaddr));
	listen(listenfd, 5);

	cout<<"Accepting connections ..."<<endl;

	int ret = pthread_create(&msg_tid, NULL, rec_msg,NULL);
	if(ret < 0)
	{
		cout<<"create recieve message pthread error!"<<endl;
	}

	/*循环判断是否有新的套接字接入*/
	while(1)
	{
		cliaddr_len = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr* )&cliaddr, &cliaddr_len);
		cout<<"connect "<<ntohs(cliaddr.sin_port)<<" suceess!"<<endl;

		ts[i].cliaddr = cliaddr;
		ts[i].connfd = connfd;

		pthread_create(&tid[i], NULL, do_work, (void* )&ts[i]);

		i++;
		pthread_num++;
	}
	return 0;
}
