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
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        //4个状态:
        //1.持有股票

        //不持有股票：两种卖出股票状态：
        //2.卖出股票：前两天卖出的度过了冷冻期，或者前一天刚卖出股票
        //3.今天刚卖出股票

        //4.今天是冷冻期，但是期限只为一天
        vector<vector<int>> dp(len,vector<int>(4,0));
        dp[0][0]=-prices[0];
        for(int i=1; i<len; i++){
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1]-prices[i],dp[i-1][3]-prices[i]));
            dp[i][1]=max(dp[i-1][1],dp[i-1][3]);
            dp[i][2]=dp[i-1][0]+prices[i];
            dp[i][3]=dp[i-1][2];
        }
        return max(dp[len-1][3],max(dp[len-1][2],dp[len-1][1]));

    }
};
// @lc code=end

