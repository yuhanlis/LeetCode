#include <iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};
class Solution{
	public:
		TreeNode * mirrorTree(TreeNode * root){
			dfs(root);
			return root;
		}
		void  dfs(TreeNode * root){
			if(root==nullptr) return ;
			TreeNode* temp = root->left;
			root->left=root->right;
			root->right=temp;
			dfs(root->left);
			dfs(root->right);
		}
};


