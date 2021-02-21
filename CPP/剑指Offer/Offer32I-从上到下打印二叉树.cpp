#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};
class Solution{
	public:
		   vector<vector<int>> levelOrder(TreeNode* root) {
		   		vector<vector<int> > ans;
				if(root==nullptr) return ans;
				queue<TreeNode * > que;
				que.push(root);
				while(!que.empty()){
					int siz=que.size();
					vector<int> temp;
					for(int i=0;i<siz;i++){
						TreeNode* temNode=que.front();
						temp.push_back(temNode->val);
						if(temNode->left!=nullptr) que.push(temNode->left);
						if(temNode->right!=nullptr) que.push(temNode->right);
						que.pop();
					}
					ans.push_back(temp);
					temp.clear();
				}
				return ans;
		   }
};
