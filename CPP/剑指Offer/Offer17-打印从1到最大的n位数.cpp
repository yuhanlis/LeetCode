#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution{
	public:
		vector<int> printNumbers(int n){
			vector<int>ans;
			int num=pow(10,n);
			for(int i=1;i<num;i++){
				ans.push_back(i);
			}
			return ans;
		}
};
