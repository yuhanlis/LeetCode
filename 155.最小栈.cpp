/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <vector>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
            top_point=-1;
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min.empty()||x<=min[min.size()-1])min.push_back(x);
        top_point++;
    }
    
    void pop() {
        if(stack[top_point]==min[min.size()-1])min.pop_back();
        stack.pop_back();
        top_point--;
    }
    
    int top() {
        return stack[top_point];
    }
    
    int getMin() {
        return min[min.size()-1];
    }
private:
    vector<int> stack;
    vector<int> min;
    int top_point=-1;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top_point();
 * int param_4 = obj->getMin();
 */
// @lc code=end

/***
 * 用一个最小值栈记录出现过的最小值
 * 删除的时候就很简单
 * ***/