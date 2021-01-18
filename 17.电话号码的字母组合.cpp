/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    string temp;
    vector<string> phone_map {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return res;
        }
        backtracking(digits,0);
        return res;
    };
    void backtracking(string digits,int pos){
        if(pos==digits.size()){
            res.push_back(temp);
            return;
        }
        string thistime=phone_map[digits[pos]-'0'];
        for(int i=0;i<thistime.size();i++){
            temp.push_back(thistime[i]);
            backtracking(digits,pos+1);
            temp.pop_back();    
        }
    }

 };

// @lc code=end

/***
 * 回溯算法
 * 格式用队列记录当前状态向下遍历
 * 遍历完之后将最后一个入队的出队即返回上一个状态
 * 改变上一个状态再重新向下遍历
 * DFS
 * **/