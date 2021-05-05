#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution{
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<string,int> unmap;
			vector<vector<string>> ans;
			int counter=0;
			for(string s:strs){
				string temp=s;
				sort(temp.begin(),temp.end());
				auto it = unmap.find(temp);
				if(it==unmap.end()){
					vector<string> newVec;
					newVec.push_back(s);
					ans.push_back(newVec);
					unmap.insert({temp,counter});
					counter++;
				} else{
					ans[it->second].push_back(s);
				}
			}
			return ans;
    	}
};
