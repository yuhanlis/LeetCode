/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include<string>
#include <iterator>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int a1,b1,c,d;
        c=0;
        string res;
        while(i>=0||j>=0){
            a1=(i>=0)?a[i]-'0':0;
            b1=(j>=0)?b[j]-'0':0;
            d=(a1+b1+c)>1?(a1+b1+c-2):(a1+b1+c);
            c=(a1+b1+c)>1?1:0;
            i--;
            j--;
            res=to_string(d)+res;
        }
        if(c==1)res=to_string(1)+res;
        return res;
    }
};
// @lc code=end


/****
 * 
 * 考虑进位即可
 * 
 * **/



int main(int argc, char const *argv[])
{
    Solution a;
    a.addBinary("11", "1");
    return 0;
}


