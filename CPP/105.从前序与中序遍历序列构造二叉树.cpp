// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem105.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**/
#include <vector>
#include <unordered_map>
 using namespace std;
//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };
 
class Solution {
public:
    unordered_map <int,int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }
        return mybuild(preorder,inorder,0,n-1,0,n-1);



    TreeNode* mybuild(vector<int>& preorder, vector<int>& inorder,int pre_l,int pre_r,int in_l,int in_r){
        if(pre_l>pre_r){
            return nullptr;
        }
        int root_val=preorder[pre_l];
        int inorder_add= index[root_val];
        int pre_size=inorder_add-in_l;
        TreeNode* root = new TreeNode(root_val);
        root->left=mybuild(preorder,inorder,pre_l+1,pre_l+pre_size,in_l,inorder_add-1);
        root->right=mybuild(preorder,inorder,pre_l+pre_size+1,pre_r,inorder_add+1,in_r);
        return root;
    }
};

// @lc code=end

