#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
	public:
    /**
     * 先按照题目要求对字典排序
     * 然后暴力双指针匹配
     * @param s
     * @param dictionary
     * @return
     */
		string findLongestWord(string s,vector<string>&dictionary){
            sort(dictionary.begin(),dictionary.end(),[](string&a,string&b){
                return a.length()>b.length()||(a.length()==b.length()&&a<b);
            });
            for(string temp:dictionary){
                int i=0,j=0;
                while (i<s.length()&&j<temp.length()){
                    if(s[i]==temp[j]){
                        j++;
                    }
                }
                if(j==temp.length()){
                    return temp;
                }
            }
		    return "";
		}
};

int main(){
    cout<<("abc">="bac")<<endl;
}
