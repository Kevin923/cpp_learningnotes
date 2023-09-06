/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(grid);
        for(int i = 1; i < n; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }

        for(int j = 1; j < m; j++) {
            dp[j][0] = grid[j][0] + dp[j - 1][0];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

