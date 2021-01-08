/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        int counter=n;
        string res;
        do
        {
            res+=(--counter)%26+'A';
            counter/=26;
        } while (counter>0);
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution a;
    a.convertToTitle(701);
    return 0;
}

/***
 * 
 * 难点：每一位都要减一映射到字母表
 * 理解:正常26进制转换，但是为A-Z，按照字母表
 * ‘A'+余数-1，但是当余数为0，即26整除26时，本应该是Z
 * 此时处理方法为余数为26，n=n-1以消去这一低位
 * 
 * 所以：(省略+'A')
 * 1. 当余数不等于0时加(n%26)-1==(n-1)%26
 * 2. 当余数等于0时加 25=（n-1）%26,并且n--以消去低位
 * 对于1，此时如果n--同样会消去此低位不会影响高位，因为余数大于1，(n-1)/26=n/26
 * 所以1，2可以合并简化代码
 * （--n)%26+'A'
 * n/=n
 * 
 * (n-1)%26=n%26-1
 * 所以可以简化代码，不判断26
 * 每一步都(--n)%26，这样当n=26时
 * **/