#include <iostream>
#include <deque>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution{
	public:
		bool isSymmetric(TreeNode* root){
			if(root==nullptr) return true;
				return myIsSymmetric(root->left,root->right);
		}

		bool myIsSymmetric(TreeNode* left,TreeNode* right){
			if(left==nullptr&&right==nullptr){
				return true;
			}else if(left==nullptr||right==nullptr){
				return false;
			}else if(left->val!=right->val){
				return false;
			}
			return myIsSymmetric(left->left,right->right)&&myIsSymmetric(left->right,right->left);
		}
};
