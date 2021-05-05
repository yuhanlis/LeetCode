#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){};
}
class Solution{
	public:
		ListNode *detectCycle(ListNode *head) {
		    if(head== nullptr) return nullptr;
		     ListNode* fast=head,*slow = head;
            while (fast!= nullptr){
                slow=slow->next;
                if(fast->next== nullptr){
                    fast=fast->next->next;
                }
                fast=fast->next;
                if(fast==slow){
                    break;
                }
            }
            ListNode* ans = head;
            if(fast!= nullptr){
                while (ans!=slow){
                    ans=ans->next;
                    slow=slow->next;
                }
            }
            return ans;

		}
};
