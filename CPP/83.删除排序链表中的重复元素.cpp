/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start

 //* Definition for singly-linked list.
    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(nullptr) {}
    // };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        while(temp!=nullptr&&temp->next!=nullptr){
            if(temp->val==temp->next->val){
                temp->next=temp->next->next;
            }else{
                temp=temp->next;
            }  
        }
        return head;
    }



    /////递归
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        head->next=deleteDuplicates(head->next);
        return head->val==head->next->val?head->next:head;
    }
    
};




// @lc code=end

