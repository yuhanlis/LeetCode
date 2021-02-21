#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){};
};
class Solution{
	public:
		ListNode* deleteNode(ListNode * head,int val){
			ListNode * temp=head;
			if(head!=nullptr&&head->val==val){
				head=head->next;
				return head;
			}
			while(temp->next!=nullptr&&temp->next->val!=val) temp=temp->next;
			temp->next=temp->next->next;
			return head;
		}
};
