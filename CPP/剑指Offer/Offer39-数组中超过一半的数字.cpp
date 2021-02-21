#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution{
	public:
		int majorityElement(vector<int>& nums){
			unordered_map<int,int> map;
			int sz=nums.size();
			int temp;
			for(int i=0;i<sz;i++){
				temp=nums[i];
				auto it=map.find(temp);
				if(it==map.end()){
					map.insert({temp,0});
					it=map.find(temp);
				}
				it->second++;
				if(it->second>=sz/2){
					return temp;
				}
			}
			return temp;
		}
};
