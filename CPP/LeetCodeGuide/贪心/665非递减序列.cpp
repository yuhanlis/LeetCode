#include <iostream>
#include <vector>
using namespace std;
/**
 * 贪心
 * 遍历一遍，如果遇到降序按照最优解改掉，继续遍历
 */
class Solution{
	public:
		bool checkPossibility(vector<int>& nums) {
		    bool flag = nums[0]<=nums[1];
            for(int i =0;i<nums.size()-1;i++){
                if(nums[i+1]<nums[i]){
                    if(flag){
                        if(nums[i+1]>=nums[i-1]){
                            nums[i]=nums[i+1];
                        }else{
                            nums[i+1]=nums[i];
                        }
                        flag= false;
                    }else{
                        return false;
                    }
                }
            }
            return true;
    }
};
