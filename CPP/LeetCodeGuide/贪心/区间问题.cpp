//
// Created by John on 2021/4/29.
//
#include <iostream>
#include <vector>
using namespace std;
/**
 * 最小区间问题，删除最少的区间使得区间不重叠
 * 思路是每次选择区间结尾最小的且不重复的，留给之后的区间就会越大
 * @param input
 * @return
 */
int NonOverlappingIntervals(vector<vector<int>>& input){
    int ans = 0;
    int num = input.size();
    sort(input.begin(),input.end(),[](vector<int>a,vector<int>b){return a[1]<b[1];});
    vector<int>previous = input[0];
    for(int i=1;i<num;i++){
        if (input[i][0]<previous[1]){
            ans++;
            num--;
        }else{
            previous = input[i];
        }
    }
    return ans;
}

int main(){
    cout<<"Input:"<<endl;
    int n;
    cin>>n;
    vector<vector<int>> input;
    while (n>0){
        vector<int>temp(2);
        cin>>temp[0];
        cin>>temp[1];
        input.push_back(temp);
        n--;
    }
    cout<<NonOverlappingIntervals(input)<<endl;
}








