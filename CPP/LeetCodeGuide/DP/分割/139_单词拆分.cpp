#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
    /*
     *自底向上dp
     * 如果该字符前面的所有字符串可以，则该字符位为真
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool>dp(n+1, false);
        dp[0] = true;
        for(int i=1 ; i<=n;i++){
            for (string word : wordDict) {
                int len = word.length();
                if(i>=len && word == s.substr(i-len,len) ){
                    dp[i]=dp[i-len]||dp[i];
                }
            }
        }
        return dp[n];
    }
};
