/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;
/***dp方法****/
class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int n=prices.size();
        int dp[n][2];
        dp[0][0]=0;
        dp[0][1]=0-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
        }
        return dp[n-1][0];
    
    
    }
};
// @lc code=end









/****贪心*****/
class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};



/*******
 * 思路1:dp
 * 在过完第i天时只有两种可能，手里还有股票/手里没有股票
 * dp里只存最大值
 * 当过完这一天还有股票时，只能前一天还有股票/今天买入股票
 * 当过完这一天没有股票时，只能在今天卖掉前一天还有的股票/前一天就没有股票
 * --------------------------------------
 * 思路2:贪心算法
 * 将所有赚钱的天加起来就是最大利润
 * 
 * l[i]-r[i]=-r[i]+r[i+1]-r[i+1]+r[i+2]-r[i+2]+......+l[i]
 * 只将r[i]-r[i-1]>0的天加起来就是最大利润
 * 贪心算法只能求出利润
 * 
 * *****/


 