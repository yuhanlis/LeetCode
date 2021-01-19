/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            vector<vector<int> >ans;
            int i=0,j=n-1;
            for(int i=0;i<n-3;i++){
                   if(i>0&&nums[i]==nums[i-1]){
                    continue;
                }
                for(int j=n-1;j>=i+3;j--){
                    if(j<n-1&&nums[j]==nums[j+1]){
                        continue;
                    }
                    int k=i+1,l=j-1;
                    while(k<l){
                        if(k>i+1&&nums[k]==nums[k-1]){   
                            k++;
                            continue;
                        }
                        if(l<j-1&&nums[l]==nums[l+1]){   
                            l--;
                            continue;
                        }
                        int sum=nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target){
                            vector<int>temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[k]);
                            temp.push_back(nums[l]);
                            temp.push_back(nums[j]);
                            ans.push_back(temp);
                            k++;
                            l--;
                        }
                        else if(sum<target){
                            k++;
                        }else{
                            l--;
                        }
                    }
                }
            }
            return ans;
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    int test[]={-2,-1,-1,1,1,2,2};
    vector<int>tests(test,test+7);
    Solution a;
    a.fourSum(tests,0);
    return 0;
}
/**
 * 双指针
 * 同三数之和
 * 固定两个移动两个
 * **/