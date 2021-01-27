/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n%2==0&&n!=0)n/=2;
        return n==1;
    }
};
// @lc code=end

