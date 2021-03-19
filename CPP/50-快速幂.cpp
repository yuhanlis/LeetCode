#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
class Solution{
	public:
		double myPow(double x, int n) {
			double ans=1,y=x;
			int bit=n;
			while(bit!=0){
				if(bit%2) ans= bit>0?ans*y:ans/y;
				bit/=2;
				y*=y;
			}	
			return ans;
 	   }

		double myPowRe(double x,int n){
			if(n==0) return 1;
			double temp = myPowRe(x,n/2);
			temp=temp*temp;
			if(n%2) temp= n>0?temp*x:temp/x;
			return temp;
		}
};
int main(){
	Solution a;
	cout<<a.myPow(2,10)<<endl;
	cout<<a.myPow(2,-10)<<endl;
	cout<<a.myPowRe(2,10)<<endl;
	cout<<a.myPowRe(2,-10)<<endl;
	return 0;
}
