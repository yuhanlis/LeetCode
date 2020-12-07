/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

//  Definition for singly-linked list.
// using namespace std;
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int Sum=((l1->val+l2->val)>=10)?l1->val+l2->val-10:l1->val+l2->val;
        ListNode* Res = new ListNode(Sum,nullptr);
        ListNode* Tail = Res;
        int C = ((l1->val+l2->val)>=10)?1:0;
        l1=l1->next;
        l2=l2->next;
        while (l1!=nullptr&&l2!=nullptr){
            Sum=((l1->val+l2->val+C)>=10)?l1->val+l2->val+C-10:l1->val+l2->val+C;
            Tail->next =new ListNode(Sum,nullptr);
            Tail=Tail->next;
            C = ((l1->val+l2->val+C)>=10)?1:0;
            l1=l1->next;
            l2=l2->next;
        }
        while (l1!=nullptr){
            Sum=(l1->val+C)>=10?l1->val+C-10:l1->val+C;
            Tail->next =new ListNode(Sum,nullptr);
            Tail=Tail->next;
            C=(l1->val+C)>=10?1:0;
            l1=l1->next;
        }
         while (l2!=nullptr){
            Sum=(l2->val+C)>=10?l2->val+C-10:l2->val+C;
            Tail->next =new ListNode(Sum,nullptr);
            Tail=Tail->next;
            C=(l2->val+C)>=10?1:0;
            l2=l2->next;
        }
        if(C==1){
            Tail->next=new ListNode(1,nullptr);
        }
        return Res;
        
    }
};
// @lc code=end

/**
 * 思路，整数相加，低位到高位进位
 * 
 * 卡在：
 * 1.尾指针为空->初始头尾指针相同才能保证头节点能连接上
 * 2.Sum加过进位了，赋值不用再加进位
 * */
