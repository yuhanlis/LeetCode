#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution{
	public:
		char firstUniqChar(string s){
			queue<char> que;
			unordered_map<char,int> map;
			int size=s.length();
			for(int i=0;i<size;i++){
				auto it=map.find(s[i]);
				if(it==map.end()){
					map.insert({s[i],0});
					que.push(s[i]);
					it=map.find(s[i]);
				}
				it->second++;
			}
			while(!que.empty()){
				auto it=map.find(que.front());
				if(it->second==1){
					return que.front();
				}
				que.pop();
			}
			return ' ';

		}

};
