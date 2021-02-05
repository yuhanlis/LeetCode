/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[128]={0},count=0,i=0,max=0,start=0;
        for(i=0;s[i]!='\0';i++){
            if(index[s[i]]>start){
                count=i-start;
                max=max>count?max:count;
                start=index[s[i]];
            }
            index[s[i]]=i+1;
        }
        count=i-start;
        return max>count?max:count;
    }
};
// @lc code=end




int main(int argc, char const *argv[])
{
    Solution a;
    cout<<a.lengthOfLongestSubstring("abcabcbb");


    return 0;
}
