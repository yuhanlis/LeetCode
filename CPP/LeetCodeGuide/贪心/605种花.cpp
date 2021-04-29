//
// Created by John on 2021/4/29.
//
#include <iostream>
#include <vector>
using namespace std;
/**
 *能种花就种
 **/
class Solution{
public:
    bool canPlaceFlowers(vector<int>&flowerbed,int n) {
        for(int i=0; i<flowerbed.size(); i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
                n--;
                if(n <= 0) return true;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};


int main(){
    Solution a;
    int ip[] = {1,0,0,0,0,1};
    vector<int>input(ip,ip+6);
    a.canPlaceFlowers(input,2);
}
