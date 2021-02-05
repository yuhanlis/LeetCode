/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[++i]=nums[j];
            }
        }
        return ++i;
    }
};
// @lc code=end

/******
 * 
 * 双指针，一个指向结果结尾，另一个遍历
 * */