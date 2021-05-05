#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
				int row = matrix.size(),column = matrix[0].size();
				vector<int> ans ;
				vector<bool> temp(column,false);
				vector<vector<bool>> visited(row,temp);
				int i=0,j=0;
				while(!visited[i][j]){
					for(;j<column&&!visited[i][j];j++){
						ans.push_back(matrix[i][j]);
						visited[i][j]=true;
					}
					j--;
					i++;
					for(;i<row&&!visited[i][j];i++){
						ans.push_back(matrix[i][j]);
						visited[i][j]=true;
					}
					i--;
					j--;
					for(;j>=0&&!visited[i][j];j--){
						ans.push_back(matrix[i][j]);
						visited[i][j]=true;
					}
					j++;
					i--;
					for(;i>=0&&!visited[i][j];i--){
						ans.push_back(matrix[i][j]);
						visited[i][j]=true;
					}
					i++;
					j++;
				}
				return ans;

		}
};
