/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start

// * Definition for a binary tree node.
#include <iostream>
using namespace std; 

	struct ListNode{

	};
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root ==nullptr)return true;
        return ddfs(root->left,root->right);
    }
    bool ddfs(TreeNode*left,TreeNode*right){
        if(left==nullptr){
            if(right==nullptr)return true;
            return false;
        }
        if(right==nullptr) return false;
        return(left->val==right->val)&&ddfs(left->left,right->right)&&ddfs(left->right,right->left);

    }
};
// @lc code=end

/*******
 * 
 * 双dfs
 * 判断是否对称，则判断左右子树是否互相对称
 * 一个指针指向左子树，一个指针指向右子树
 * 左子树左移，右子树右移
 * 左子树右移，右子树左移
 * 
 * ****/
int main(void){
	TreeNode * temp=new TreeNode(20);
	Solution a;
	a.isSymmetric(temp);
	cout<<a.isSymmetric(temp);
	return 0;
}




int main(){
	
}



#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		
};
