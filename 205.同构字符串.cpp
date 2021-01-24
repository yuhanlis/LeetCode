/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include<unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;
        int i=0;
        for( i=0;i<n;i++){
            if(s_map.find(s[i])==s_map.end()&&t_map.find(t[i])==t_map.end()){
                s_map.insert({s[i],i});
                t_map.insert({t[i],i});
            }else{
                auto s_f=s_map.find(s[i]);
                auto t_f=t_map.find(t[i]);
                if(s_f==s_map.end()||t_f==s_map.end()) break;
                if(s_f->second!=t_f->second) break;
                
            }
        }
        return i==n;
    }
};
// @lc code=end

/**
 * 哈希表
 * 用哈希表存储字母最先出现的位置
 * 对后续出现的字母查找位置
 * **/