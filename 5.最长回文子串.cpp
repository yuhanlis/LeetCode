/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        string res="";
            for(int l=0;l<s.size();l++){
                for(int i=0;i+l<s.size();i++){
                    int j=i+l;
                    if(l==0)dp[i][i]=true;
                    else if(l==1)dp[i][j]=(s[i]==s[j]);
                    else{
                        dp[i][j]=(dp[i+1][j-1]&&s[i]==s[j]);
                    }
                    if(dp[i][j]&&(l+1)>res.size()){
                        res=s.substr(i,l+1);        
                    }
                }
            }
        return res;
    }
};
// @lc code=end


/********
 * 
 * 
 * 思路：动态规划
 * 维护二维数组dp[][]判断字串状态
 * 对于字串Si--Sj，如果Si+1--Sj-1是回文子串并且Si=Sj，则Si-Sj是回文子串
 * 对于边界的维护：
 *          长度为1的字串永远为回文串
 *          长度为2的子串特殊判断   
 * 自底向上的动态规划，逆拓扑
 * 时间复杂度O(n)
 * 
 * */