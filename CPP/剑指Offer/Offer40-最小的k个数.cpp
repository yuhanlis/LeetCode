#include <vector>
#include <iostream>
using namespace std;
class Solution{
	public:
		vector<int> getLeastNumbers(vector<int>& arr,int k){
			int min=10001;
			vector<int> ans;
			for(int i=0;i<k;i++){
				int flg=i;
				for(int j=i;j<(int)arr.size();j++){
					if(min>arr[j]) {
						min=arr[j];
						flg=j;
					}
				}
				arr[flg]=arr[i];
				arr[i]=min;
				ans.push_back(min);
			}
			return ans;
		}
		vector<int>  quickSort(vector<int>&arr,int l,int r,int k){
			vector<int> ans;
			int select=arr[l];
			int left=l,right=r;
			while(l<r){
				while(arr[l]<=select) l++;
				while(arr[r]>select) r--;
				int temp=arr[l];
				arr[l]=arr[r];
				arr[r]=temp;
			}
			arr[left]=arr[l];
			arr[l]=select;
			if(l>k) return quickSort(arr,left,l,k);
			if(l<k) return quickSort(arr,l+1,right,k);
			ans.assign(arr.begin(),arr.begin()+k);
			return ans;
		}
};
