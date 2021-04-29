/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int mx=0;
			int n=nums.size();
			for(int i=0;i<n;i++){
				mx=max(mx,i+nums[i]);
			}
			return mx>=n-1;
    }
};
// @lc code=en
int main(){
	int num[]={2,3,1,1,4};
	vector<int> nums(num,num+5);
	Solution a;
	a.canJump(nums);
}
