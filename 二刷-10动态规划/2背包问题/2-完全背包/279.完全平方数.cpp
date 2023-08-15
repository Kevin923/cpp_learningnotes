/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
/*
我来把题目翻译一下：完全平方数就是物品（可以无限件使用），
凑个正整数n就是背包，问凑满这个背包最少有多少物品？
*/
    int numSquares(int n) {
        //dp[j] : 组成和为j的完全平方数的最小数量为dp[j]
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        //先遍历物品 再遍历背包

        for(int i = 1; i * i <= n; i++) {
            for(int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[n];
    
    }
};
// @lc code=end

