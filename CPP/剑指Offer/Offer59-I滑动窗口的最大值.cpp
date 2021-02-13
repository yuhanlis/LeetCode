#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution{
	public:
		vector<int> maxSlidingWindow(vector<int> &nums,int k){
			deque<int> dq;
			int n=nums.size();
			vector<int> ans;
			for(int i=0;i<n;i++){
				while(!dq.empty()&& i-dq.front()>=k)dq.pop_front();
				while(!dq.empty()&&nums[dq.back()]<nums[i]) dq.pop_back();
				dq.push_back(i);
				if(i>=k-1) ans.push_back(nums[dq.front()]);
			}
			return ans;
		}
};
int main()
{
	vector<int> nums;
	int k;
	cout<<"Input k:"<<endl;
	cin>>k;
	cout<<"Input nums:"<<endl;
	int num;
	while(cin>>num){
		if(num==-1000) break;
		nums.push_back(num);
	}
	Solution a;
	vector<int> res = a.maxSlidingWindow(nums,k);
	for(int temp:res){
		cout<<temp<<'\t';
	}
	cout<<endl;
	return 0;
}
