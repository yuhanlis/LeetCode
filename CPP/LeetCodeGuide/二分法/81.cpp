#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
    /**
     * 找到有序部分二分
     * @param nums
     * @param target
     * @return
     */
		bool search(vector<int>&nums,int target){
	        int l = 0 , r = nums.size()-1;
            while (l<=r){
                int mid = l+(r-l)/2;
                if(nums[mid]==target) {
                    l = r = mid;
                    return true;
                }
                if(nums[l]==nums[mid]){
                    l++;
                }
                if(nums[l]<nums[mid]){
                    if(nums[mid]>=target&&nums[l]<=target){
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                } else {
                    if (nums[mid] <= target && nums[r] >= target) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            return false;

		}
};
