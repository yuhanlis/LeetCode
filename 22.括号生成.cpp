/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector <string> ans;
    string temp;
    void backtracking(int n,int l,int r){
        if(r==n){
            ans.push_back(temp);
            return;
        }
        if(l<n){
            temp.push_back('(');
            backtracking(n,l+1,r);
            temp.pop_back();
            }
        if(r<l){
            temp.push_back(')');
            backtracking(n,l,r+1);
            temp.pop_back();
        }
    }    
    vector<string> generateParenthesis(int n) {
        backtracking(n,0,0);
        return ans;
    }
};
// @lc code=end

/**
 * 一定先左括号再右括号
 * 每一个括号匹配之前，右括号数一定小于等于左括号数
 * 回溯
 * */