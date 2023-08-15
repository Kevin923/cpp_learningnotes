/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    //贪心
    int maxProfit(vector<int>& prices) {
        //寻找最大利润区间， 左边最小和右边最大的值 做差
        int res = 0;
        int left = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            left = min(left, prices[i]);
            res = max(res, prices[i] - left);
        }
        return res;
        
    }
//可贪心可动规
    // int maxProfit(vector<int>& prices) {
    //     //dp[i][0]:第i天持有股票所得的最大现金数 (持有，考虑买入)
    //     //dp[i][1]:第i天不持有股票所得的最大现金数 （不持有，考虑卖出）
    //     //持有 不等于 当天买入
    //     int len = prices.size();
    //     if(len == 0) return 0;
    //     vector<vector<int>> dp(len, vector<int>(2));
    //     dp[0][0] = -prices[0];
    //     dp[0][1] = 0;

    //     for(int i = 1; i < len; i++) {
    //         //前一天买，今天买 都是负数 所以取max 看哪个花的少
    //         dp[i][0] = max(dp[i - 1][0], -prices[i]);
    //         dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    //     }

    //     return dp[len - 1][1];
    // }
};
// @lc code=end

