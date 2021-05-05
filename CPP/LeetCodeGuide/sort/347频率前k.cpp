#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution{
	public:
    bool cmp(pair<int,int>&m,pair<int,int>&n){
        return m.second>n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>numMap;
        for(int temp : nums){
            auto it = numMap.find(temp);
            if(it == numMap.end()){
                numMap.insert({temp,1});
            } else{
                it->second++;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>  q(cmp);
        for(auto item : numMap){
            if(q.size()==k){
                if(q.top().second<item.second){
                    q.pop();
                    q.push(item);
                }
            } else{
                q.push(item);
            }
        }

        vector<int>ans;
        while (!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
