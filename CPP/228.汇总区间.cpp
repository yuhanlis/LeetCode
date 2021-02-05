/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        if(n==0)return ans;
        string temp;
        int i=0;
        while(i<n){
            int low=i++;
            while(i<n&&nums[i]==nums[i-1]+1) i++;
            int high=i-1;
            temp=to_string(nums[low]);
            if(high!=low){
                temp+="->";
                temp+=to_string(nums[high]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

