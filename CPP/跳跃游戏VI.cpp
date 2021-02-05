#include<vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp;
        deque<int > que;
        int res=0;
        que.push_back(0);
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            while(!que.empty()&&que.front()<(i-k))que.pop_front();      //找到满足跳跃距离小于k并且dp最大的值
            dp.push_back(dp[que.front()]+nums[i]);
            while(!que.empty()&&dp[i]>dp[que.back()])que.pop_back();    //将新位置插入到队列尾部，将小于他的删除（此值大且新之后的不会再用到）
            que.push_back(i);
        }
    return dp[nums.size()-1];
    }
};


/*******
 * 单调队列优化的动态规划
 * 用单调队列存储dp[i]最大的角标
 * 只需要维护大小为k的队列，而不用维护i-k～i的最大值
 * 时间复杂度O(n)
 * 
 * 
 * 
 * 
 * 不优化 如下 时间复杂度O(n2);
 * 
 * 
 * **********/



class Solution2 {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i==0)dp.push_back(nums[0]);
            else if(i>0&&i<k){
                dp.push_back(nums[i]+*max_element(dp.begin(),dp.end()));
            }
            else
            {
                dp.push_back(nums[i]+*max_element(dp.end()-k,dp.end()));
            }
            
        }
    return dp[nums.size()-1];
    }
};