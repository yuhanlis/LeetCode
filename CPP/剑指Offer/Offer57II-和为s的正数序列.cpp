#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		vector<vector<int> > findContinuousSequence(int target){
			vector<vector<int> > ans;
			vector<int> path;
			solidWindows(ans,target);
			return ans;
		};
		void backtracking(vector<vector<int> >& ans,vector<int> path,int target,int i,int sum){
			if(sum==target){
				
				ans.push_back(path);
				return ;
			}
			for(;i<target;i++){
				sum+=i;
				path.push_back(i);
				backtracking(ans,path,target,i+1,sum);
				sum-=i;
				path.pop_back();
			}
		}

		void solidWindows(vector<vector<int> >&ans,int target){
			int first=1;
			while(first<target){
				vector<int>temp;
				int second=first+1;
				int sum=first+second;
				temp.push_back(first);
				temp.push_back(second);
				while(sum<target){
					second++;
					sum+=second;
					temp.push_back(second);
				}
				if(sum==target){
					ans.push_back(temp);
				}
				first++;
			}
		
		}
};
int main()
{
	int num;
	cin>>num;
	Solution a;
	auto temp=a.findContinuousSequence(num);
	for(auto path:temp){
		for(auto num:path)
			cout<<num<<"\t";
		cout << endl;
	}
}

