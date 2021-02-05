/******
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <deque>
using namespace std;
class MyStack {
private:
    deque<int> queue;
    int top_val;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue.push_back(x);
        top_val=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size=queue.size();
        for(int i=0;i<size-1;i++){
            queue.push_back(queue.front());
            this->top_val=queue.front();
            queue.pop_front();
        }
        int val=queue.front();
        queue.pop_front();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

