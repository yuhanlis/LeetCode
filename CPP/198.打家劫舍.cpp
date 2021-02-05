/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> ans(nums.size());
        ans[0]=nums[0];
        ans[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            ans[i]=max(ans[i-1],ans[i-2]+nums[i]);
        }
        return ans[n-1];
    }
};
// @lc code=end
/**
 * dp
 * dp[n]=max(dp[n-1],dp[n-2]+nums[n])
 * 打第n家时只有偷或不偷
 * 不偷则只能时第n-1最大值
 * 偷则是dp[n-2]+nums[n]
 * */
