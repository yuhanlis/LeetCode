#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){};
};
class Solution{
	public:
		ListNode * rotateRight(ListNode * head, int k){
			ListNode* ans = head;
			ListNode* temp = head;
			while(temp->next!=nullptr){
				temp=temp->next;
			}
			temp->next=head;
			for(int count=1;count<k;count++){
				ans=ans->next;
			}	
			head=ans->next;
			ans->next=nullptr;
			return head;
		}		
};
