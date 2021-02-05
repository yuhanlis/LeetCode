/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        int C = digits[i]+1>=10?1:0;
        if(C==1){
            digits[i--]=0;
        }else{
            digits[i]+=1;
        }
        while(C==1&&i>=0){
            C=digits[i]+1>=10?1:0;
            if(C==1)digits[i--]=0;
            else{
                digits[i]+=1;
                break;
            }
        }
        if(i==-1&&C>=1){
            auto it = digits.begin();
            digits.insert(it,1);
        }

        return digits;
    }
};
// @lc code=end


/*******
 * 
 * 思路：考虑进位
 * 易错：考虑循环边界：最高位进位，最高位+1但不进位
 * ******/