#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    /**
     * 改变r，不要动l我也不知道为啥，反正l顺序不通过，r就能通过
     * @param nums
     * @return
     */
    int findMin(vector<int>&nums){
        if(nums.size()==1||nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        int l = 0 , r = nums.size()-1;
        while (l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] == nums[r]){
                r--;
            } else if (nums[mid]<nums[r]){
                r=mid;
            } else {
                l = mid+1;
            }
        }
        return nums[r];
    }
};
