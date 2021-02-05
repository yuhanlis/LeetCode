/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=nullptr&&head->val==val)head=head->next;
        ListNode*temp=head;
        while (temp!=nullptr)
        {
            while(temp->next!=nullptr&&temp->next->val==val)temp->next=temp->next->next;
            temp=temp->next;
        }
        return head;
    }
};
// @lc code=end

