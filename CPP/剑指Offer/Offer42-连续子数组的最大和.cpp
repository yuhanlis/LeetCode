#include <vector>
#include <iostream>
using namespace std;
class Solution{
	public:
		int maxSubArray(vector<int> & nums){
			int n=nums.size();
			int ans=INT_MIN;
			vector<int> dp(n);
			dp[0]=nums[0];
			for(int i=1;i<n;i++){
				dp[i]=dp[i-1]>0?nums[i]+dp[i-1]:nums[i];
				ans=max(ans,dp[i]);
			}
			return ans;
		}
};
