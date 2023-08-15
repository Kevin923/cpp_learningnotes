/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //左上角 右下角有障碍直接返回0
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        //初始化dp
        for(int i=0; i<m && obstacleGrid[i][0]==0; i++){
            dp[i][0]=1;
        } 
        for(int j=0; j<n && obstacleGrid[0][j]==0; j++){
            dp[0][j]=1;
        }

        //遍历
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]!=1){
                    dp[i][j]=dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

