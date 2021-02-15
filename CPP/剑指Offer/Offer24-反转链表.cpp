#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
struct ListNode {
	      int val;
		  ListNode *next;
	      ListNode(int x) : val(x), next(NULL) {};
};

class Solution{
	public:
		ListNode* reverseList(ListNode* head){
			ListNode* ans=nullptr;
			while(head!=nullptr){
				ListNode* temp=head->next;
				head->next=ans;
				ans=head;
				head=temp;
			}
			return ans;
		}

		ListNode* recursion(ListNode * head){
			if(head==nullptr||head->next==nullptr){
				return head;
			}
			ListNode * node=recursion(head->next);
			head->next->next=head;
			head->next=nullptr;
			return node;
		}
};
