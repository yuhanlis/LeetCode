#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int mySqrt(int x){
        int l=1,r=x;
        while (l<=r){
            int mid = l+(r-l)/2; //防止越界的巧妙算法
            int sqrt=x/mid;
            if(sqrt==mid){
                return mid;
            }else if(sqrt>mid){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return r;
    }
};
