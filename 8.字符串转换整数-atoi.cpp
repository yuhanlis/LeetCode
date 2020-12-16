/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <limits.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int minus = 0;
        int res=0;
        for(;s[i]==' ';i++);    //跳过空格
        if(s[i]=='+'||s[i]>='0'&&(s[i]<='9')){
            if(s[i]=='+')i++;
            while (s[i]>='0'&&s[i]<='9')
            {
                if(res>INT_MAX/10||(res==INT_MAX/10&&s[i]-'0'>7)) return INT_MAX;
                
                res=res*10+(s[i]-'0');
                i++;
            }
            return res;
        }else if(s[i]=='-'){
            i++;
            while (s[i]>='0'&&s[i]<='9')
            {
                if(res<INT_MIN/10||(res==INT_MIN/10&&s[i]-'0'>8))return INT_MIN;
                res=res*10-(s[i]-'0');
                i++;
            }
            return res;
        }else
        {
            return 0;
        }
        
    }
   
};
// @lc code=end

/******
 * 
 * 思路：正常遍历字符串
 * 
 * 考点：越界问题
 * 
 * 对int类型越界判断：
 * int范围：-2147483648----2147483647
 * 判断res操作后越界只需判断
 * res>214748364||res==214748364&a>7
 * 负数一样
 * 
 * 注意:
 * res=res*10-s[i]-'0'这里res按顺序计算，即先加s[i]的ASCII码
 * 此时如果越界则不会减‘0’的ASCII码直接异常，正常要先算s[i]-'0'得到要
 * 加的int值；
 * 
 * ******/