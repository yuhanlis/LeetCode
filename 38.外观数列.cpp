/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        if(n==1) return res;
        for(int i=1;i<n;i++)
        res=count(res);
        return res;

    };

    string count(string a){
        int counter=0;
        char temp=a[0];
        string res="";
        for(int i=0;i<a.length();i++){
            if(a[i]==temp) counter++;
            else{
                res.append(to_string(counter));
                res.append(to_string(temp-'0'));
                counter=1;
                temp=a[i];
            }
        }
        res.append(to_string(counter));
        res.append(to_string(temp-'0'));
        return res;
    }

};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution a;
    a.countAndSay(3);
    return 0;
}



