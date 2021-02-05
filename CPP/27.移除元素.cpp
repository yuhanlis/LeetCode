/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()<2){
            if(nums.size()==0) return 0;
            if(nums[0]==val){
                return 0;
            }
            return nums.size();
        }
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i++]=nums[j];
            }
        }
        return i;
    }
};
// @lc code=end

/**********
 * 双指针
 * 注意：数组只有一个元素但是正为要删除的那个元素
 * ********/

