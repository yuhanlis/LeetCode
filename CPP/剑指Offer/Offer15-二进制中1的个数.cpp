#include <iostream>
using namespace std;
// class Solution{
// 	public:
// 		int hammingWeight(uint32_t n){
// 			int ans=0;
// 			while(n>0){
// 				ans+=n&1;
// 				n>>=1;
// 			}
// 			return ans;
// 		}
// };


class Solution {
public:
    int hammingWeight(uint32_t n) {
        return ((bitset<32>)n).count();
    }
};
int main()
{
	Solution a;
	cout<<a.hammingWeight(3)<<'\t'<<a.hammingWeight(2)<<'\t'<<a.hammingWeight(0)<<endl;
	return 0;
}
