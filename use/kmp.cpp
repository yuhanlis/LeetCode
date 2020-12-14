#include <iostream>
#include <string>
using namespace std;
class KMPalgorithm{
    public:
        int KMP(int *next,string S,string T){
            int i=0,j=0;
            this->GetNext(next,T);
            while(S[i]!='\0'&&T[j]!='\0'){
                if(j==-1||S[i]==T[j]){
                    i++;
                    j++;
                }else
                {
                    j=next[j];
                }
                
            }
            if(T[j]=='\0') return i-j;
            else return -1;

        }
        void GetNext(int * next,string T){
            int j=0,k=-1;
            next[j]=k;
            while(T[j]!='\0')
            {
                if(k==-1||T[j]==T[k])
                {
                    j++;
                    k++;
                    next[j]=k;
                }
                else k=next[k];
	        }
        }
};


int main(int argc, char const *argv[])
{
    KMPalgorithm a=KMPalgorithm();
    string S="hello";
    string T="ll";
    int next[T.size()];
    cout<<a.KMP(next,S,T)<<endl;
    cout<<"hello world"<<endl;
    return 0;
}
