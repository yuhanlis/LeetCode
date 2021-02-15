#include <iostream>
using namespace std;
class Solution{
	public:
		int add(int a,int b){
			while(b!=0){
				int temp=a^b;
				b=(a&b)<<1;
				a=temp;
			}
			return a;
		}
};
int main()
{
	Solution a;
	int num1,num2;
	cin>>num1>>num2;
	cout<<a.add(num1,num2)<<endl;
}
