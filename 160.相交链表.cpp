/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto A=headA,B=headB;
        while (A!=B)
        {
            A=A!=nullptr?A->next:headB;
            B=B!=nullptr?B->next:headA;
        }
        return A;
        
    }
};
// @lc code=end



/******
 * A:a+c+b
 * B:b+c+a
 * 走完相遇
 * 否则平行
 * ******/