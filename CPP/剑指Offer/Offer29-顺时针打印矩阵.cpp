#include <vector>
#include <iostream>
using namespace std;
class Solution{
	public:
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector <int> ans;
			int i,j;
			int height=matrix.size(),width=matrix[0].size();
			vector<bool> temp(width,false);
			vector<vector<bool>> visited(height,temp);
			int direction=0;
			i=j=0;
			while(i>=0&&i<height&&j>=0&&j<width&&!visited[i][j]){
				ans.push_back(matrix[i][j]);
				visited[i][j]=true;
				if(direction==0){
					if(j+1<width&&!visited[i][j+1]){
						j++;
					}else{
						direction=1;
						i++;
					}
				}else if(direction==1){
					if(i+1<height&&!visited[i+1][j]){
						i++;
					}else{
						direction=2;
						j--;
					}
				}else if(direction==3){
					if(j-1>=0&&!visited[j][j-1]){
						j--;
					}else{
						direction=4;
						i--;;
					}
				}else{
					if(i-1>=0&&!visited[i-1][j]){
						i--;
					}else{
						direction=1;
						j++;
					}
				}
			}
			return ans;
		
		}
		
};
