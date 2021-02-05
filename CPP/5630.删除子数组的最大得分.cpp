class Solution {
    bool b[10005];
    int s[100005];
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),i,j,ans=0;
        for(i=0;i<n;i++)s[i+1]=s[i]+nums[i];
        memset(b,0,sizeof(b));
        for(i=j=0;i<n;i++)
        {
            for(;j<n&&!b[nums[j]];j++)b[nums[j]]=1;
            ans=max(ans,s[j]-s[i]);
            b[nums[i]]=0;
        }
        return ans;
    }
};

/****
 * 周赛第二解法：
 * 双指针，一个指向开始，一个指向能到达的最远的数（第二个相同之前）
 * 在开始指针未跳过最远的数之前，最远的指针不会移动
 * **/