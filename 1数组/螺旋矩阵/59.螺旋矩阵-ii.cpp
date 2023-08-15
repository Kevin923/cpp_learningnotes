/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int loop=n/2;
        int mid=n/2;
        int count=1;
        int offset=1;
        int startx=0,starty=0;
        int i,j;
        while(loop--)
        {
            i=startx;
            j=starty;
            //填充上行； 1 2(左闭右开)
            for(j=starty;j<n-offset;j++){
                res[startx][j]=count++;
            }

            //填充右列； 3 4（左闭右开）
            for(i=startx;i<n-offset;i++){
                res[i][j]=count++;
            }

            //填充下行 5 6
            for(;j>starty;j--){
                res[i][j]=count++;
            }

            //填充左列 7 8
            for(;i>startx;i--){
                res[i][j]=count++;
            }
            offset+=1;
            //例如第一圈从（0，0）开始 第二圈则从(1,1)开始
            startx++;
            starty++;
        }
        if(n%2==1){
            res[mid][mid]=count;
        }
        return res;
    }
};
// @lc code=end

