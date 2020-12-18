/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int n1=1;
        int n2=2;
        if(n==1)return 1;
        for(int i=3;i<=n;i++){
            int temp=n1+n2;
            n1=n2;
            n2=temp;
        }
        return n2;
        
    }
};
// @lc code=end


/**********
 * dp[n]=dp[n-1]+dp[n-2]
 * 最后一步只能爬一层dp[n-1]或两层dp[n-2]
 * 
 斐波那契数列 
 * **********/