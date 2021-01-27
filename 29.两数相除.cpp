/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool mins=false;
         // 当除数为1，直接返回被除数
        if (divisor == 1) {
            return dividend;
        }
        // 当除数为-1且被除数为Integer.MIN_VALUE时，将会溢出，返回Integer.MAX_VALUE
        if (divisor == -1 && dividend == -__INT_MAX__-1) {
            return __INT_MAX__;
        }
        if(dividend<0){
            mins=!mins;
        }else
        {
            dividend=-dividend;
        }
        
        if(divisor<=0){
            mins=!mins;
        }else
        {
            divisor=-divisor;
        }
        
        int ans=0;
         while(dividend<=divisor){
            int temp=divisor;
            int c=1;
            while(dividend-temp<=temp) {
				temp=temp+temp;
				c=c+c;
			}
            dividend-=temp;
            ans+=c;
        }
        return mins?-ans:ans;
    }
};
// @lc code=end

/**
 * 快速幂
 * 每次减尽可能多的被除数
 * O(log2N)
 * */