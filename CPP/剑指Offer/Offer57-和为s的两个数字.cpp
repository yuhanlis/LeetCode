#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		vector<int> twoSum(vector<int>&nums,int target){
			int size=nums.size();
			vector<int> ans;
			int l=0,r=size-1;
			while(l<r){
				int sum=nums[l]+nums[r];
				if(sum==target){
					ans.push_back(nums[l]);
					ans.push_back(nums[r]);
					return ans;
				}else if(sum<target){
					l++;
				}else{
					r--;
				}
			}
			return ans;
		}
	
};
