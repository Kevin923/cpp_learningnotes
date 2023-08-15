/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;

        //完全背包 先遍历物品 在遍历背包 此题与顺序无关
        //正序遍历物品可重复多次放入  0-1背包一维dp倒序遍历
        for(int i=0; i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                if(j>=coins[i] && dp[j-coins[i]]!=INT_MAX){
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }

        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};
// @lc code=end

