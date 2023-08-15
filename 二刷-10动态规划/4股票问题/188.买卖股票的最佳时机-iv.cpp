/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
/*
    上一题进阶版
    二维数组 dp[i][j] ：
    第i天的状态为j，所剩下的最大现金是dp[i][j]
    除0以外 j为奇数就是买入（持有） 偶数就是卖出（不持有）
*/
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;

        vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));

        //dp初始化
        for(int i = 1; i < 2 * k; i += 2) {
            dp[0][i] = -prices[0];
        }

        for(int i = 1; i < len; i++) {
            for(int j = 0; j < 2 * k - 1; j += 2) {
                //奇数买（持有）
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                
                //偶数卖(不持有)
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[len - 1][2 * k];
    }
};
// @lc code=end

