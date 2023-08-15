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
    //奇数是买，偶数是卖   0，1，2，3，4，5，6.....2k
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(2*k+1,0));
        for(int j=1; j< 2*k; j+=2){
            dp[0][j]=-prices[0];
        }

        for(int i=1; i<prices.size(); i++){
            for(int j=1; j<2*k; j+=2){
                //买
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]-prices[i]);
                //卖
                dp[i][j+1]=max(dp[i-1][j+1],dp[i-1][j]+prices[i]);
            }
        }

        return dp[len-1][2*k];
    }
};
// @lc code=end

