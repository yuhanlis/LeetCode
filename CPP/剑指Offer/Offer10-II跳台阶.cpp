#include <iostream>
#include <vector>
#define MOD 1000000007;
using namespace std;
class Solution{
	public:
		int newWays(int n ){
			vector<int > dp(n);
			dp[0]=1;
			dp[1]=2;
			for(int i=2;i<n;i++){
				dp[i]=(dp[i-1]+dp[i-2])%MOD;
			}
			return dp[n-1];
		}

};
int main()
{
	Solution a;
	cout<<a.newWays(7);
}
