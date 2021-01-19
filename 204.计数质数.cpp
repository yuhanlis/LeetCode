/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int countPrimes2(int n) {
        int ans=0;
        for(int i=2;i<n;i++){
            if(isPrime(i))ans++;
        }
        return ans;
    }
    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
/**
 * 埃尔筛法
 * a是质数则2a,3a,4a....是合数
 * 由于n之前的都乘过，从n*n开始计
 * 可以标记所有的合数
 * **/
    int countPrimes(int n){
        vector<int> isPrime(n,1);
        int ans=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                ans++;
                if((long long)i*i<n){
                for(int j=i*i;j<n;j+=i){
                    isPrime[j]=0;
                }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/**
 * 判断是否是质数优化
 * 判断较小因数即可
 * 较小的因数一定在2-n^1/2中
 * 时间复杂度可以降为0～n^1/2
 * **/
