#include <iostream>

using namespace std;
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution{
	public:
		int kthLargest(TreeNode* root,int k){
			int ans,i=0;
			miOrderDfs(root,k,i,ans);
			return ans;
		};
		void  miOrderDfs(TreeNode *root,int k,int& i,int& ans){
			if(root == nullptr){
				return ;	
			}
			miOrderDfs(root->right,k,i,ans);
			i+=1;
			if(i==k){
				ans=root->val;
				return ;
			}
			miOrderDfs(root->left,k,i,ans);
		}
};
