/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    stack<char> Stack;
    bool isValid(string s) {
        if(s.size()==0){
            return true;
        }
        for(int i=0;i<s.size();i++){
            char temp=s.at(i);
            if(temp=='('||temp=='['||temp=='{')Stack.push(temp); //遇到左括号压栈
            else if(temp==')'||temp==']'||temp=='}'){
                if(Stack.empty())return false;  //如果直接遇到右括号返回false
                switch (temp)
                {
                case ')':   //匹配出栈，不匹配返回
                    if(Stack.top()!='('){
                        return false;
                    }else
                    {
                        Stack.pop();
                    }
                    break;
                case ']':   //匹配出栈，不匹配返回
                    if(Stack.top()!='['){
                        return false;
                    }else
                    {
                        Stack.pop();
                    }
                    break;
                case '}':   //匹配出栈，不匹配返回
                    if(Stack.top()!='{'){
                        return false;
                    }else
                    {
                        Stack.pop();
                    }
                    break;
                
                default:
                    break;
                }
            }
        }
        if(Stack.empty()){      //最后栈为空则返回true
            return true;
        }
        return false;

    }
};
// @lc code=end

/**
 * 
 * 思路：
 * 使用栈（先进后出），遇到左括号入栈，
 * 如果遇到右括号，看是否和最近的左括号匹配（栈顶）
 * 如果最后栈为空则全部匹配，如果还有左括号则不匹配
 * 
 * 注意：特殊情况，栈为空直接遇到右括号
 * 
 * */