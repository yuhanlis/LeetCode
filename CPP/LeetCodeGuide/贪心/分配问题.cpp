//
// Created by John on 2021/4/29.
//
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;
int findContentChildren(vector<int>&children,vector<int>&cookies){
   sort(children.begin(),children.end());
   int ans = 0;
   for(int cookie : cookies){
       if(children[ans]<cookie) ans++;
   }
   return ans;
}


/**糖果问题，评分比身旁高的🍬比身旁多*/
int candy(vector<int>&grades){
    int n = grades.size();
    vector<int>candys(n,1);
    for(int i=0;i<n-1;i++){
        if(grades[i+1]>grades[i]){
            candys[i+1]++;
        }
    }
    for(int i=n-1;i>=1;i--){
        if(grades[i-1]>grades[i]&&candys[i-1]<=candys[i]){
            candys[i-1]++;
        }
    }
    return accumulate(candys.begin(),candys.end(),0);
}
int main(){
    /*
    int children[] = {1,2,3,4,5};
    int cookie[] = {2,4,5,5};
    vector<int> chd(children,children+5);
    vector<int> cook(cookie,cookie+4);
    cout<<findContentChildren(chd,cook)<<endl;
     */
    int grades[]={1,0,2};
    vector<int>grade(grades,grades+3);
    cout<<candy(grade)<<endl;
}