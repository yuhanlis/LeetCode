#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class Solution{
	public:
		string reverseLeftWords(string s,int n){
			string ans;
			ans=s.substr(n,s.length()-n);
			ans+=s.substr(0,n);
			return ans;
		}
};
int main()
{
	Solution a;
	string s="abcdefg";
	cout<<a.reverseLeftWords(s,3)<<endl;
	return 0;
}
