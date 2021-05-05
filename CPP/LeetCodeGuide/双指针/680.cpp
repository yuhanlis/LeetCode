#include <iostream>
#include <vector>d
#include <string>
using namespace std;
class Solution{
	public:
        /**
         * 不相等时要满足左右两个子串其一是回文串
         * @param s
         * @return
         */
		bool validPalindrome(string s) {
            int i=0,j=s.length()-1;
            bool flag = true;
            while (i<j) {
                if(s[i]==s[j]){
                    ++i;
                    --j;
                }else{
                    return isValid(s,i+1,j)||isValid(s,i,j-1);
                }
            }
            return true;
		}
		bool isValid(string s,int i,int j){
            while (i<j){
                if(s[i]!=s[j]){
                    return false;
                }
                ++i;
                --j;
            }
            return true;
		}
};
int main(){
    Solution a;
    a.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
}