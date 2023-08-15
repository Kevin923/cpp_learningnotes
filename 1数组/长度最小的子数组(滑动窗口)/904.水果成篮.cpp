/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include<iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int res=0;
        int ln=fruits[i];
        int rn=fruits[j];
        while(j<fruits.size())
        {
            if(fruits[j]==rn || fruits[j]==ln){
                res=max(res,j-i+1);
                j++;
            }
            else{
                i=j-1;
                ln=fruits[i];
                while(i>=1 && fruits[i-1]==ln)
                    i--;
                rn=fruits[j];
                res=max(res,j-i+1);
            }
        }
        return res;

    }
};


// @lc code=end

