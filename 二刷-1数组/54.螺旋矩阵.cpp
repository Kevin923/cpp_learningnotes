/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i, j = 0;
        int loop = min(m, n) / 2;
        int startx, starty = 0;
        int index = 1;
        vector<int> res;
        while(loop--){
            i = startx;
            j = starty;
            //上行
            for(j = starty; j < n - index; j++){
                res.push_back(matrix[startx][j]);
            }

            //右列
            for(i = startx; i < m - index; i++){
                res.push_back(matrix[i][j]);
            }

            //下行
            for(; j > starty; j--){
                res.push_back(matrix[i][j]);
            }

            //左列
            for(; i > startx; i--){
                res.push_back(matrix[i][starty]);
            }
            startx++;
            starty++;
            index++;
        }
        //添加中间行或列
        int mid = min(m, n) / 2;
        if(min(m, n) % 2 == 1){
            if(m > n){
                //列
                for(int k = mid; k < m - index + 1; k++){
                    res.push_back(matrix[k][mid]);
                }
            }
            else{
                //行
                for(int k = mid; k < n - index + 1; k++){
                    res.push_back(matrix[mid][k]);
                }
            }
        }
        //提示 i < startX +  m - n + 1; 
        //以及 i < startX  + n - m + 1; 中间列 / 中间行个数
        return res;
    }
};
// @lc code=end

