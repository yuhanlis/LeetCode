/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        int q=nums.size()/2;
        for(int n:nums){
            if(++mp[n]>q)return n;
        }
        return -1;
    }
};
// @lc code=end

