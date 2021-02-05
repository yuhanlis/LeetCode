/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while (n>0)
        {
            count+=n/5;
            n/=5;
        }
        return count;
        
    }
};
// @lc code=end
/**
 * 看有多少个五
 * 其中25两个，125三个·····
 * 即为5的个数+25的个数+125的个数。。。。。。
 * */
