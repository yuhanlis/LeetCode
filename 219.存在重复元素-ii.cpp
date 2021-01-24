/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ans=false;
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            auto iterator = map.find(nums[i]);
            if(iterator!=map.end()){
                if(i-iterator->second<=k){
                    ans=true;
                    break;
                }else{
                    iterator->second=i;
                }
            }else{
                map.insert({nums[i],i});
            }
        }
        return ans;
    }
};
// @lc code=end

