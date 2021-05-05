#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/**
 * 最小覆盖子串
 * 双指针，先右右移找到较大的覆盖子串
 * 再左左移，找到较小的子串
 */
class Solution{
public:
    string minWindow(string s, string t) {
        string ans;
        unordered_map<char,int> map;
        unordered_map<char,int> flags;
        for(char a:t){
            auto it = map.find(a);
            if(it == map.end()){
                map.insert({a,1});
                flags.insert({a,0});
            }
            else
                it->second++;
        }
        int l = 0, r = 0,cnt=0;
        for(;r<s.size();++r) {
            auto it = flags.find(s[r]);
            if (it != flags.end()) {
                if (it->second <map[it->first]) {
                    cnt++;
                }
                it->second++;

            }
            while (cnt == t.size()) {
                if (ans.size() == 0 || (r - l + 1) < ans.size()) {
                    ans = s.substr(l, r - l + 1);
                }
                auto it = flags.find(s[l]);
                if (it != flags.end()) {
                    --(it->second);
                    if(it->second<map[it->first])
                        --cnt;
                }
                ++l;
            }
        }
        return ans;
    }
};

int main(){
    Solution a;
    a.minWindow("ADOBECODEBANC","ABC");
}