/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
/*
状态一dp[i][0]：持有股票状态（今天买入股票，或者是之前就买入了股票然后没有操作，一直持有）

不持有股票状态，这里就有两种卖出股票状态:
状态二dp[i][1]：保持卖出股票的状态（两天前就卖出了股票，度过一天冷冻期。或者是前一天就是卖出股票状态，一直没操作）
状态三dp[i][2]：今天卖出股票

状态四dp[i][3]：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！
*/
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            //达到冷冻期状态，昨天卖出了股票
            dp[i][3] = dp[i - 1][2];
        }

        return max(dp[len - 1][3], max(dp[len - 1][2], dp[len - 1][1]));
    }
};
// @lc code=end

