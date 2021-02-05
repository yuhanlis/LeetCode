/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
        ListNode* fast=head;
        ListNode* slow=head;
        do{
            if(fast==nullptr||fast->next==nullptr)return false;
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);
        return true;
    }
};
// @lc code=end

/********
 * 龟兔赛跑
 * 一起开跑，有环的话快的和慢的总会相遇
 * *****/