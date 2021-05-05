#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int>ans(2,0);
            int l=0,r=nums.size()-1;
            while (l<=r){
                int mid = l+(r-l)/2;
                if(nums[mid]==target){
                    r=mid;
                    break;
                } else if (target[mid]<target){
                    l++;
                } else{
                    r--;
                }
            }
            if(l>r){
                return new vector<int>(2,-1);
            }
            while (r>=0&&nums[r]==target)r--;
            while (l<nums.size()&&nums[l]==target)l++;
            ans[0]=r+1;
            ans[1]=l-1;
            return ans;

        }
		
};
