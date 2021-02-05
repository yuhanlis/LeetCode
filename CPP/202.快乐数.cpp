/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include<unordered_set>
using namespace std;
class Solution {
public:
    unordered_set<int> map;
    bool isHappy(int n) {
        if(n==1)return true;
        else if(map.find(n)!=map.end())return false;
        else
        {
            map.insert(n);
            n=calcute(n);
            return isHappy(n);
        }
        
        
    }
    int calcute(int n){
        int ans=0;
        while(n>0){
            ans+=(n%10)*(n%10);
            n/=10;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution a;
    a.isHappy(19);
    return 0;
}

/**
 * 如果最后结果不能到1则会陷入循环
 * 用哈希表记录出现过的值，出现过返回false
 * 未出现过返回向下计算
 * 1返回true
 * */