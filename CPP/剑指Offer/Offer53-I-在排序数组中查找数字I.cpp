#include <vector>
#include <iostream>
using namespace std;
class Solution{
	public:
		int search(vector<int>& nums,int target){
			int ans=0;
			int n=nums.size();
			if(n==0) return 0;
			int left=0,right=n-1;
			while(left<right){
				int mid=(left+right)/2;
				if(nums[mid]==target){
					left=mid;
					break;
				}else if(nums[mid]<target){
					left=mid+1;
				}else{
					right=mid-1;
				}
			}
			if(nums[left]==target){
				right=left+1;
				while(left>=0&&nums[left--]==target) ans++;
				while(right<n&&nums[right++]==target) ans++;
			}
			return ans;
		}
};
int main()
{
	int num[]={1,2,2,3,3,3,4,5,6};
	vector<int> nums(num,num+9);
	Solution a;
	a.search(nums,3);
	return 0;
}
