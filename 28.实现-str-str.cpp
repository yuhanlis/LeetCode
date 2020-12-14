/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
using namespace std;
class KMPalgorithm{
    public:
        int KMP(int *next,string S,string T){
            int i=0,j=0;
            this->GetNext(next,T);
            while(S[i]!='\0'&&T[j]!='\0'){
                if(j==-1||S[i]==T[j]){
                    i++;
                    j++;
                }else
                {
                    j=next[j];
                }
                
            }
            free(next);
            if(T[j]=='\0') return i-j;
            else return -1;

        }
        void GetNext(int * next,string T){
            int j=0,k=-1;
            next[j]=k;
            while(T[j]!='\0')
            {
                if(k==-1||T[j]==T[k])
                {
                    j++;
                    k++;
                    next[j]=k;
                }
                else k=next[k];
	        }
        }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int next[needle.size()];
        KMPalgorithm kmp= KMPalgorithm();
        return kmp.KMP(next,haystack,needle);
    }
};



/******
 * 
 * 思路：
 * 1.暴力搜索，双指针
 * 
 * 2.KMP算法：
 *       相同前后缀字串，移动T，S不移动，减少回溯
 *       求next数组（递归/非递归）：
 *          pk=pj，next[j+1]=next[j]+1
 *          pk!=pj,令k=next[k]向前搜索最短相同前后缀
 *       相等++，不相等i不变，j=next[j](即T向后移动j-next[j]个字符) 
 * 
 * 
 * 
// @lc code=end

