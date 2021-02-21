#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		vector<int> exchange(vector<int>& nums){
			int size=nums.size();
			int l=0,r=size;
			while(l<r){
				while(nums[l++]%2==1);
				while(nums[r--]%2==0);
				swap(nums[l],nums[r]);
			}
			return nums;
		
		}
};
