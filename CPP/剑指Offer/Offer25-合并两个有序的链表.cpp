#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){};
};

class Solution{
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
			if(l1==nullptr) return l2;
			if(l2==nullptr) return l1;
			ListNode * res;
			if(l1->val<l2->val){
				res=new ListNode(l1->val);
				l1=l1->next;
			}else{
				res=new ListNode(l2->val);
				l2=l2->next;
			}
			ListNode * ans = res->next;
			while(l1!=nullptr&&l2!=nullptr){
				if(l1->val<l2->val){
					ans=new ListNode(l1->val);
					l1=l1->next;
				}else{
					ans=new ListNode(l2->val);
					l2=l2->next;
				}
				ans=ans->next;
			}
			ans=l1==nullptr?l2:l1;
			return res;

		}
};
