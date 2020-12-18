/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
 //* Definition for a binary tree node.
 #include <vector>
 #include <queue>
 using namespace std;
//    struct TreeNode {
//        int val;
//        TreeNode *left;
//        TreeNode *right;
//        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//    };
 
class Solution {
    vector<vector<int>> res;
    queue<TreeNode*> Que;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr)return res;
        
        Que.push(root);
        while (!Que.empty())
        {
            auto temp=vector<int>();
            int size=Que.size();
            for(int i=0;i<size;i++){
                TreeNode* t=Que.front();
                temp.push_back(t->val);
                if(t->left)Que.push(t->left);
                if(t->right)Que.push(t->right);
                Que.pop();
            }
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
}


// @lc code=end


/****
 * dfs
 * 最后反转
 * ***/