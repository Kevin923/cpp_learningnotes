/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    // int fib(int n) {
    //     if(n==0) return 0;
    //     if(n==1) return 1;

    //     return fib(n-1)+fib(n-2);
    // }

    //动态规划
    int fib(int n) {
        if(n<2) return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end

