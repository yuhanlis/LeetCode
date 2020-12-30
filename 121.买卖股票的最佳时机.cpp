/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int n=prices.size();
        int res = 0;
        vector<int>min(n);
        min[0]=prices[0];
        for(int i=1;i<prices.size();i++){
            min[i]=min[i-1]<prices[i]?min[i-1]:prices[i];
            if(prices[i]>min[i]){
                int profit = prices[i]-min[i];
                res=res>profit?res:profit;
            }
        }
        return res;
    }
};
// @lc code=end


/****
 * 思路：dp
 * 遍历过程记录下到prices[i]之前的最小的股票价格
 * min[i]=min(min[i-1],prices[i])
 * 最大利润为prices[i]-min[i]
 * 时间复杂度O(n)
 * **/

