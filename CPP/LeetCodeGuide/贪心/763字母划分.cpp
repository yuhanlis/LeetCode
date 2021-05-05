#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution{
	public:
    /**
     * 思路：贪心
     * 每次找最早出现的字母，记录它最晚出现的位置
     * 每次找最早出现的字母，判断有没有交叉，有交叉则将字串延长至交叉最后
     * @param S
     * @return
     */
		vector<int> partitionLabels(string S) {
			vector<vector<int>> storige;
			unordered_map<char,vector<int>> map;
			for(int i=0;i<S.length();i++){
				auto it = map.find(S[i]);
				if(it == map.end()){
				    vector<int>temp(2,i);
				    map.insert({S[i],temp});
				}else{
				    it->second[1]=i;
				}
			}
			for(auto it:map){
			    storige.push_back(it.second);
			}

			sort(storige.begin(),storige.end(),[](vector<int>a,vector<int>b){return a[0]<b[0];});

			vector<int>ans;
			int pre = storige[0][1];
			int st = 0;
			for(int i=1;i<storige.size();i++){
			    if(storige[i][0]<pre){
			        pre = max(storige[i][1],pre);
			    } else{
			        ans.push_back(pre-st+1);
			        st = storige[i][0];
			        pre = storige[i][1];
			    }
			}
            ans.push_back(pre-st+1);
			return ans;
		}
};
