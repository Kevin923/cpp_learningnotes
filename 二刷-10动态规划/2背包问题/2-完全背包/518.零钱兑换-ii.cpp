/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //if(coins.size() == 1 && coins[0] < amount) return 0;
        //dp[j]装满j，有几种组合方式
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
                /*  
                    二维：dp[i][j] = dp[i - 1][j] + dp[i - 1][j - coins[i]]
                    一维展开：dp[j] = dp[j] + dp[j - coins[i]];
                    等式右边dp[j] : 表示 i 不放 的组合数
                    等式右边dp[j - coins[i]] : 放i 能组成金额j的组合数
                */
            }
        }
        return dp[amount];
    }
};
// @lc code=end

