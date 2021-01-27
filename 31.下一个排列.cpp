/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        for(i;i>=0&&nums[i]>=nums[i+1];i--);
        if(i>=0){
        int j=nums.size()-1;
        for(j;nums[i]>=nums[j];j--);
        swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
// @lc code=end

/**
 * 字典序 升序->先增后降->降序
 *          （大数前移）
 * 从右往前找到非降序的开始，和后面大于他的较小的数交换（从后往前看先升序再降序）
 * 最靠右的较小的数和他右面大于它的最小的数交换，小数之后升序排列即为下一个字典顺
 * 再将之后的数升序排列
 * */