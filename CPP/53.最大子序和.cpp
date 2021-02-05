/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
            for(int i=1;i<nums.size();i++){
                nums[i]=(nums[i]>nums[i]+nums[i-1])?nums[i]:nums[i]+nums[i-1];
                res=(nums[i]>res)?nums[i]:res;
            }
        return res;
    }
};
// @lc code=end



/*******************
 * 
 * 动态规划
 * 子问题：每个数值之前的串的最大和
 * 条件：如果数值之前的串的和加本数最大则本数变为最大数值
 * 边界：0
 * *******/ 