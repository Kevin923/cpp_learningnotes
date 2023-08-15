/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;

//dp做法：
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        vector<vector<int>> dp(len,vector<int>(2,0));
        dp[0][0]-=prices[0];
        dp[0][1]=0;
        //dp[i][0]:第i天持有股票所得最多现金 (考虑买股票，可能在第i天把之前买得卖了再买，或者在i-1
        //天就买了)
        //dp[i][1]:第i天不持有股票所得最多现金  (考虑卖股票)
        for(int i=1; i<len; i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);//唯一与121不同得地方
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[len-1][1];
    }
};
// @lc code=end

