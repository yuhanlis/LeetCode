#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Solution{
	public:
		int findRepeatNumber(vector<int>& nums){
			unordered_map<int,int> map;
			for(int i=0;i<(int)nums.size();i++){
				auto it=map.find(nums[i]);
				if(it==map.end()){
					map.insert({nums[i],0});	
				}else{
					return nums[i];
				}
			}
			return nums[nums.size()-1];
		}
};
