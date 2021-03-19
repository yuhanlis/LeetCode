#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int jump(vector<int>& nums) {
			int n=nums.size();
			vector<int> dp(n,n);
			dp[0]=0;
			for(int i=0;i<n;i++){
				for(int j=1;(j+i)<n&&j<=nums[i];j++){
					dp[j+i]=min(dp[i]+1,dp[j+i]);
				}
			}
			return dp[n-1];
	    }
};

int main(){
	int num[]={2,3,1,1,4};
	vector<int>nums(num,num+5);
	Solution a;
	cout<<a.jump(nums)<<endl;
}
