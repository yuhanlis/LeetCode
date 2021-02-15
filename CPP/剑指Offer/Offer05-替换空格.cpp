#include <iostream>
#include <string>
using namespace std;
class Solution{
	public:
		string replaceSpace(string s){
			int n=s.length();
			string ans="";
			for(int i=0;i<n;i++){
				if(s[i]==' '){
					ans+="%20";
				}else{
					ans+=s[i];
				}
			}
			return ans;
		}
};
int main()
{
	string s="a b c  d   e";
	Solution a;
	cout<<a.replaceSpace(s);
	return 0;
}
