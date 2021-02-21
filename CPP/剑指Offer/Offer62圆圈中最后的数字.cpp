#include <iostream>
using namespace std;
class Solution{
	public:
		int lastRemaining(int n,int m){
        	int i,s=0;
       		 for(i=2;i<=n;i++){
           		 s=(s+m)%i;
				 cout<<s<<endl;
       		 }
			 	cout<<s<<endl;
    	    return s;
 	   }			
};

int main()
{
	Solution a;
	int m,n;
	cin>>n>>m;
	a.lastRemaining(n,m);
}
