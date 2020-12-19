/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string res="";
        while(num>=1000){
            num-=1000;
            res+="M";
        }
        while(num >=900){
            num-=900;
            res+="CM";
        }
         while(num >=500){
            num-=500;
            res+="D";
        }
         while(num >=400){
            num-=400;
            res+="CD";
        }
         while(num >=100){
            num-=100;
            res+="C";
        }
         while(num >=90){
            num-=90;
            res+="XC";
        }
         while(num >=50){
            num-=50;
            res+="L";
        }
         while(num >=40){
            num-=40;
            res+="XL";
        }
         while(num >=10){
            num-=10;
            res+="X";
        }
         while(num >=9){
            num-=9;
            res+="IX";
        }
         while(num >=5){
            num-=5;
            res+="V";
        }
         while(num >=4){
            num-=4;
            res+="IV";
        }
         while(num >=1){
            num-=1;
            res+="I";
        }
        return res;
    }
};

// @lc code=end



/*******
 * 从小到大循环遍历
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 可硬编码千百十位
 * 
 * 
 * 
 * 
 * 
 * ***///