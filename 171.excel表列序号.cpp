#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
           ans=ans*26+(s[i]-'A')+1;//不能加字母，会加ASCII码可能越界
        }
        return ans;
    }
};
// @lc code=end


/**
 * K进制化为10进制
 * */