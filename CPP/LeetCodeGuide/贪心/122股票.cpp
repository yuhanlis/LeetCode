#include <iostream>
#include <vector>
using namespace std;
/**
 * 找到最大的几个为正值的区间
 * a[ri]-a[li]<=>a[ri]-a[ri-1]+a[ri-1]-a[ri-2].....+a[li+1]-a[li]
 * 贪心，把所有的贡献值是正值的加起来
 */
class Solution{
	public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            ans+=max(0,prices[i]-prices[i-1]);
        }
        return ans;
    }
};
