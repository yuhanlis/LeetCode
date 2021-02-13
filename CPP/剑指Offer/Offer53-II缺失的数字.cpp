#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int missingNumber(vector<int>&nums){
			int left=0,right=nums.size()-1;
			int mid=0;
			while(left<=right){
				mid=left+right/2;
				if(nums[mid]!=mid) right = mid-1;
				else  left=mid+1;
			}
			return left;
		}
};
