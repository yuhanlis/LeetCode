//
// Created by John on 2021/4/29.
//
/**
 * 按照身高降序，按照位置升序
 * 低的看不到高的，低的插入到高的前面
 */
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>&a,vector<int>&b){return a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]);});
        vector<vector<int>> ans;
        for(auto it : people){
            ans.insert(ans.begin()+it[1],it);
        }
        return ans;
    }
};
