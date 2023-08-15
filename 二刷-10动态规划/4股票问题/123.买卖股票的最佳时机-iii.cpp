/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
/*
0.没有操作 （其实我们也可以不设置这个状态）
1.第一次持有股票
2.第一次不持有股票
3.第二次持有股票
4.第二次不持有股票

dp[i][j]中 i表示第i天，j为 [0 - 4] 五个状态，
dp[i][j]表示第i天状态j所剩最大现金。
*/
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for(int i = 1; i < len; i++) {
            dp[i][0] = dp[i - 1][0]; //可省略不写
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[len - 1][4];
    }
};
// @lc code=end

