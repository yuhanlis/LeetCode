/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        bool ans=false;
        unordered_map<int,int > hash;
        int i=0;
        for(i=0;i<n;i++){
            auto temp=hash.find(nums[i]);
            if(temp!=hash.end()){
                temp->second++;
                if(temp->second>=2){
                    ans=true;
                    break;
                }
                
            }else{
                hash.insert({nums[i],1});
            }
            
            
        }
        return ans;
    }
};
// @lc code=end

/**
 * 哈希表
 * */