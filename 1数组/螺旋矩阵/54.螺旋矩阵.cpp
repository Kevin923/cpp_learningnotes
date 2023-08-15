/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //m行 n列
        int m=matrix.size();
        int n=matrix[0].size();
        int startx=0,starty=0;
        int loop=min(m,n)/2;
        int mid=min(m,n)/2;
        vector<int> res;
        int i,j;
        int offset=1;

        while(loop--)
        {
            i=startx;
            j=starty;
            for(j=starty;j<n-offset;j++)
                res.push_back(matrix[startx][j]);

            for(i=startx;i<m-offset;i++){
                res.push_back(matrix[i][j]);
            }

            for(;j>starty;j--){
                res.push_back(matrix[i][j]);
            }

            for(;i>startx;i--){
                res.push_back(matrix[i][starty]);
            }
            offset++;
            startx++;
            starty++;
        }
        if(min(m,n)%2==1){
            if(m>n)
            {
                //添加最中间一列
                for(int k=mid;k<m-offset+1;k++){
                    res.push_back(matrix[k][mid]);
                }
            }
            else{
                //添加最中间一行
                for(int k=mid;k<n-offset+1;k++){
                    res.push_back(matrix[mid][k]);
                }
            }

        }
        return res;
    }
};
// @lc code=end

