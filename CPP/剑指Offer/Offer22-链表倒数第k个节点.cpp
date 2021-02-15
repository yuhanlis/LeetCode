#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
	public:
		ListNode *getKthFromEnd(ListNode * head,int k){
			ListNode * first,*second;
			first=new ListNode(-1);
			first->next=head;
			second=head;
			for(int i=0;i<k&&second!=nullptr;i++) second=second->next;
			while(second!=nullptr){
				first=first->next;
				second=second->next;
			}
			return first;
		}
};
