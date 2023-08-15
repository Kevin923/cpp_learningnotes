/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int i = 0, j = 0;
        int left = fruits[i]; //左边水果篮
        int right = fruits[j];  //右边

        while(j < fruits.size()){
            if(fruits[j] == right || fruits[j] == left){
                res = max(res, j - i + 1);
                j++;
            }
            else{
                i = j - 1;  //重置左边水果篮位置
                left = fruits[i]; //更新
                while(i >= 1 && fruits[i - 1] == left){
                    i--;
                }
                right = fruits[j];
                res = max(res, j - i + 1);
            }
        }
        return res; 
    }

};
// @lc code=end

 