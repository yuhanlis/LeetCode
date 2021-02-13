#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) :val(x),left(nullptr),right(nullptr){};
};
class Solution {
	public:
		bool isBalanced(TreeNode* root){
			bool ans = true;
			dfs(root,ans);
			return ans;
		}

		int dfs(TreeNode* root,bool & ans){
			if(root==nullptr){
				return 0;
			}
			int leftdeepth,rightdeepth;
			if(ans){
				leftdeepth=dfs(root->left,ans);
				rightdeepth=dfs(root->right,ans);
				if(leftdeepth-rightdeepth>1||rightdeepth-leftdeepth>1){
					ans=false;
				}
			}
			return max(leftdeepth,rightdeepth)+1;
		}
		
};
int main()
{

	Solution a;
	vector <int> temp;
	TreeNode * b;
	
}
