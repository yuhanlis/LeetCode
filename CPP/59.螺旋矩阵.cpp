/**
 *暴力解螺旋矩阵
 *直接四个状态模拟
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> ans;
			if(n==1){
				vector<int> temp(1,1);
				ans.push_back(temp);
				return ans;
			}
			for(int i=0;i<n;i++){
				vector<int> temp(n);
				ans.push_back(temp);
			}
			int row=0,column=0,num=1,state=0;
			while(ans[row][column]==0){
			ans[row][column]=num++;
			if(state==0){
				if((column+1)<n&&ans[row][column+1]==0) column++;
				else{
					row++;
					state=(state+1)%4;
				}
			}
			else if(state == 1){
				if((row+1)<n&&ans[row+1][column]==0) row++;
				else{
					column--;
					state=(state+1)%4;
				}
			}
			else if(state == 2){
				if((column-1)>=0&&ans[row][column-1]==0) column--;
				else{
					row--;
					state=(state+1)%4;
				}
			}
			else if(state == 3){
				if((row-1)>=0&&ans[row-1][column]==0) row--;
				else{
					column++;
					state=(state+1)%4;
				}
			}
			}
			return ans;
		}
};
