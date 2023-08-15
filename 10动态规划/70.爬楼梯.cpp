/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>
using namespace std;

class Solution {
public:
    // int climbStairs(int n) {
    //     if(n<=2) return n;
    //     vector<int> dp(n+1);
    //     dp[1]=1;
    //     dp[2]=2;
    //     for(int i=3; i<=n ;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

    //优化版本，不适用额外空间
    int climbStairs(int n) {
        if(n<=2) return n;
        int dp[3];
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++){
            int sum=dp[1]+dp[2];
            dp[1]=dp[2];
            dp[2]=sum;
        }
        return dp[2];
    }

};
// @lc code=end

