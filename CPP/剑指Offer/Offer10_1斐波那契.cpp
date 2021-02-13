#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
class Solution{
	public:
		int fib(int n){
			if(n==0) return 0;
			else if( n==1) return 1;
			int a = 0;
			int b=1;
			for(int i=0;i<n;i++){
				a=a+b;
				b=a-b;
				a%=MOD;
			}
			return a;
		};		
};
int main()
{
	Solution a;
	cout<<a.fib(5)<<endl;
	return 0;
}
