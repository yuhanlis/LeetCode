/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        if(n==1)return nums[0];
        for(i=0;i<n;i++){
            if(i==0){
                if(nums[i]<nums[i+1])break;
            }
            else if(i==n-1){
                if(nums[i]>nums[i-1])
                break;
            }else{
                if(nums[i]>nums[i-1]&&nums[i]<nums[i+1])
                break;
            }
        }
        return nums[i];
    }
};
// @lc code=end

