/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> matrix(min(numRows, int(s.size())));
        string res = "";
        int i=0 ;
        int row=0;
        int j=0;
        while (i<s.length())
        {
            for(j=0;j<numRows;j++){
                if(i==s.length()) break;
                matrix[row]+=s[i];
                row++;
                i++;
                
            }
            row-=2;
            j-=2;
            for(;j>0;j--){
                if(i==s.length()) break;
                matrix[row]+=s[i];
                row--;
                i++;
            }
        }
        for(i=0;i<matrix.size();i++)res.append(matrix[i]);
        return res;

        
    }

};


/*****
 * 
 * 
 * 
 * 思路：用矩阵构建模型
 * 
 * ***/
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution a;
    a.convert("PAYPALISHIRING",4);
    return 0;
}

