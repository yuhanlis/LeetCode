#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(nullptr){};
};
class Solution{
	public:
		ListNode* getIntersectionNode(ListNode* headA,ListNode * headB){
			ListNode* tempA,*tempB;
			tempA=headA;
			tempB=headB;
			while(tempA!=tempB){
			 tempA= tempA==nullptr? headB:tempA->next;
			 tempB= tempB==nullptr? headA:tempB->next;
			}
			return tempA;
		
		};
		

};

