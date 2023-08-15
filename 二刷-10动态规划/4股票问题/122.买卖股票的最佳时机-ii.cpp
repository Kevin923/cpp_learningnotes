/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    /*
    动规：与121.买卖股票的最佳时机，只在递推公式有一处不同,
    即dp[i][0] = dp[i - 1][1] - prices[i] 因为变成了可买卖多次了
    121是只允许买卖一次，因为股票全程只能买卖一次，所以如果买入股票，
    那么第i天持有股票即dp[i][0]一定就是 -prices[i]。
    */

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        //0:持有 1：不持有
        for(int i = 1; i < len; i++) {
            //与121唯一一处不同
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[len - 1][1];
    }
};
// @lc code=end

