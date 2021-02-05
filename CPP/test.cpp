#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>

#include <algorithm>  //vector成员函数头文件，否则没有max_element.....
using namespace std;
class Solution {
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
int main(int argc, char const *argv[])
{
    Solution a;
    int num[]={1,-1,-2,4,-7,3};
    vector<int>nums(num,num+6);
    
    cout<<a.maxResult(nums, 2);
    return 0;
}
