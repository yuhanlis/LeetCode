/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
#include <vector>
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       vector<ListNode*> stack;
       ListNode* temp=head;
       while(temp!=nullptr){
           stack.push_back(temp);
           temp=temp->next;
       } 
       if(stack.size()==1&&n==1)return nullptr;
       if(stack.size()==n){
           return stack[1];
       }
       ListNode* front=stack[stack.size()-n-1];
       front->next=front->next->next;
       return stack[0];
    }
};
// @lc code=end

/**
 * 用栈记录所有位置
 * **/


/**
 * 双指针
 * first second
 * first超前second n个
 * second是null时 first时倒数第n个；
 * **/