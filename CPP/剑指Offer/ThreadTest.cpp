#include <iostream>
#include <thread>
using namespace std;
void hello(){
	cout<<"Hello world"<<endl;
}
void pause_thread(int n){
	this_thread::sleep_for(chrono::seconds(n));
	cout<<"pausee of "<<n<<" seconds ended"<<endl;
}

int main()
{
	thread t(hello);
	t.join();
	thread a(hello);
	a.detach();
	thread threads[5];
	for(int i=0;i<5;i++){
		threads[i]=thread(pause_thread,i+1);
	}
	cout << "Done spawning threads. Now waiting for them to join:\n";
	for(auto &temp:threads)
		temp.join();
	cout<<"All threads joined"<<endl;
}
