/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
#include <string>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       int ans=0;
       int i=32;
       while(i--){
           ans<<=1;
           ans+=n&1;
           n>>=1;
       }
       return ans;

    }
};
// @lc code=end

