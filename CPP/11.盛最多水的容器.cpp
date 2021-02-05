/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i=0,j=height.size()-1;
        while(i<j){
                int heigh=height[i]<height[j]?height[i]:height[j];
                int weigh=j-i;
                int volume = heigh*weigh;
                res=res<volume?volume:res;
                if(height[i]<height[j])i++;
                else j--;
        }
        
        return res;
    }
};
// @lc code=end

/**************
 * 两层for太慢
 * 双指针
 * 每次将较短的那条向内侧移动才可能保证体积增大
 * （底相同-1，只有高变大，体积才可能变大）
 * 动了可能变差，但一直动最差的可能会变好
 * 
 * 
 * *************/
