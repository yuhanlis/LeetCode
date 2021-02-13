#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
	bool isStraight(vector<int> & nums){
		vector<bool> visited(13,false);
		int maxnum=0,minnum=12;
		for(int n:nums){
			if(n==0) continue;
			maxnum=max(maxnum,n);
			minnum=min(minnum,n);
			if(visited[n-1]) return false;
			visited[n-1]=true;
		}
		return maxnum-minnum<=4;
	}
};
