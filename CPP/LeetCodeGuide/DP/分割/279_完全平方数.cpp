#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
    /**
     * 割木头
     * O(n*n)
     * dp[i] = min(dp[i-1],dp[i-4].....)+1
     * 自底向上的动态规划
     * @param n
     * @return
     */
    int numSquares(int n) {
        vector<int>dp(n+1,n);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i],dp[i-j*j])+1;
            }
        }
        return dp[n];
    }
};
