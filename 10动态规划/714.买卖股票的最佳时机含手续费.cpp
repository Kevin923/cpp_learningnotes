/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2,0));
        dp[0][0]-=prices[0];
        //dp[i][0] 表示第i天持有股票所省最多现金 (买花的最少)
        //dp[i][1] 表示第i天不持有股票所得最多现金
        for(int i=1; i<len; i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]-fee);
        }
        return dp[len-1][1];
    }
};
// @lc code=end

