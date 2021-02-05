/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        int i = s.size()-1;
        while(i>0&&(s[i]==' '||s[i]=='\0'))i--;
        if(i<0)return 0;
        while(s[i]!=' '&&i>=0){
            i--;
            res++;
        }
        return res;
    }
};
// @lc code=end

/******************
 * 
 * 易错点：
 * 考虑边界，访问越界问题
 * 
 * ***************/