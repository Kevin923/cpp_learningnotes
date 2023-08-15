/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2]=1;
        for(int i=3; i<=n; i++){
            for(int j=1; j<i; j++){
                //因为dp[i]是在for循环内，每次都会产生新的值，最后取最大的dp[i];
                dp[i]=max(dp[i],max((i-j)*j,dp[i-j]*j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

