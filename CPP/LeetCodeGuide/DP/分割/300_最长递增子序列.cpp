#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
        /**
         * 自底向上递归
         * O(n2)
         * @param nums
         * @return
         */
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            vector<int> dp(n,1);
            for(int i=0;i<n;i++) {
                for (int j=0;j<i;j++) {
                    if(nums[i]>nums[j]){
                        dp[i] = max(dp[i],dp[j]+1);
                    }
                }
                ans = max(ans,dp[i]);
            }
            return ans;
        }

        /**
         * 二分法，永远维护递增的,
         * 贪心，每次把小的加进去
         * @param nums
         * @return
         */
    int lengthOfLIS(vector<int>& nums){
            vector<int>dp;
            int n = nums.size();
            dp.push_back(nums[0]);
            for(int i=1;i<n;++i) {
                if(dp.back()<nums[i]){
                    dp.push_back(nums[i]);
                }else {
                    auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
                    *it = nums[i];
                }
            }
            return dp.size();
        }


};
