#include <climits>
#include <iostream>
using namespace std;
template <class T>
void Merge(T arr[], int l, int q, int r){
    int n=r-l+1;//临时数组存合并后的有序序列
    T* tmp=new T[n];
    int i=0;
    int left=l;
    int right=q+1;
    while(left<=q && right<=r)
        tmp[i++] = arr[left]<= arr[right]?arr[left++]:arr[right++];
    while(left<=q)
        tmp[i++]=arr[left++];
    while(right<=r)
        tmp[i++]=arr[right++];
    for(int j=0;j<n;++j)
        arr[l+j]=tmp[j];
    delete [] tmp;//删掉堆区的内存
}
template <class T>
void MergeSort(T arr[], int l, int r){
    if(l==r)
        return;  //递归基是让数组中的每个数单独成为长度为1的区间
    int q = (l + r)/2;
    MergeSort(arr, l, q);
    MergeSort(arr, q + 1, r);
    Merge(arr, l, q, r);
    
}


int main(){
	int nums[11]={1,3,2,5,7,3,4,6,8,2,10};
	for (int i = 0;  i <11 ; ++ i) {
		std::cout << nums[i] << '\t';
	}
	cout<<endl;
	MergeSort(nums,0,10);
	for (int i = 0;  i <11 ; ++ i) {
		std::cout << nums[i] << '\t';
	}
	cout<<endl;
}
