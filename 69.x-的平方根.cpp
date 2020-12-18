/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int min=0;
        int max=x;
        int res;
        while(min<=max){
            long mid=(min+max)/2;
            if(mid*mid<=x){
                res=mid;
                min=mid+1;
            }else{
                max=mid-1;
            }
        }
        return res;
    }
};
// @lc code=end

