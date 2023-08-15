/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int loop = n / 2; //转圈赋值次数
        int startx, starty = 0; //每圈开始的位置
        int count = 1;
        int i,j;
        int index = 1;
        while(loop){
            i = startx;
            j = starty;
            //上行从左右到右 左开右闭
            for(j = starty; j < n - index; j++){
                res[startx][j] = count++;
            }

            //右列
            for(i = startx; i < n - index; i++){
                res[i][j] = count++;
            }

            //下行
            for(; j > starty; j--){
                res[i][j] = count++;
            }

            //左列
            for(; i > startx; i--){
                res[i][j] = count++;
            }

            loop--;
            startx += 1; //下一圈的起始位置(1,1)
            starty += 1;
            index += 1; //下一圈的左闭右开的右开  n - index
        }
        
        //奇数 中间位置需要自己赋值
        if(n % 2 ==1){
            int mid = n / 2;
            res[mid][mid] = count;
        }
        return res;
    }
};
// @lc code=end

