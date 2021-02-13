#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution{
	public:
		string reverseWords(string s){
			stack<string > sstack;
			string temp;
			for(int i=0;i<s.length();i++){
				char a=s[i];
				if(a==' '){
					if(!temp.empty()) {
						sstack.push(temp);	
						temp="";
					}
					continue;
				}
				temp+=a;
			}
			if(!temp.empty()) sstack.push(temp);
			if(sstack.empty()) return "";
			string ans="";
			while(sstack.size()!=1){
				ans+=sstack.top();
				ans+=" ";
				sstack.pop();
			}
			ans+=sstack.top();
			return ans;
		}
};
int main()
{
	Solution a;
	string s="the sky is blue";
	cout<<a.reverseWords(s);
	return 0;
}
