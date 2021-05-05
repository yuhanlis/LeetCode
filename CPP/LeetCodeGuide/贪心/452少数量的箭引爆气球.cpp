#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    /**
     *  气球问题
     *  同435,扎最尾值最小的能扎足够多的重合的
     * @param points
     * @return
     */
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>a,vector<int>b){ return a[1]<b[1];});
        int ans = 1;
        int x = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>x){
                ans++;
                x=points[i][1];
            }
        }
        return ans;
    }
};

