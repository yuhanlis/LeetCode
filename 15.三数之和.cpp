/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])continue;//去重，已经算过的跳过
            int L=i+1,R=nums.size()-1;
            while(L<R){
                vector<int>temp;
                if(L>i+1&&nums[L]==nums[L-1]){      //去重
                    L++;
                    continue;
                }
                if(R<nums.size()-1&&nums[R]==nums[R+1]){    //去重
                    R--;
                    continue;
                }
                if((nums[i]+nums[L]+nums[R])==0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[L]);
                    temp.push_back(nums[R]);
                    res.push_back(temp);
                    L++;
                    R--;
                }else if((nums[i]+nums[L]+nums[R])<0){
                    L++;
                }else{
                    R--;
                }
            }
        }
    return res;
    }
};
// @lc code=end



/*****
 * 双指针
 * 和问题：先排序（方便去重和遍历）
 * 类似二分，和大，大值内移，和小，小值内移，和等，一起内移
 * 
 * ***/