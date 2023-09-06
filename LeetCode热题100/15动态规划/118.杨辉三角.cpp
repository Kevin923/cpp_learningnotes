/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        for(int i = 0; i < numRows; i++) {
            dp[i] = vector<int>(i + 1, 1);
            if(i > 1) {
                int size = dp[i].size();
                for(int j = 1; j <= size - 2; j++) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp;
    }
};
// @lc code=end

