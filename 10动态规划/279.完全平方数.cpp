/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

// class Solution {
// public:
//     //一维dp
//     int numSquares(int n) {
//         vector<int> dp(n+1,INT_MAX);
//         dp[0]=0;

//         for(int i=1; i*i<=n; i++){
//             for(int j=i*i; j<=n;j++){
//                 dp[j]=min(dp[j],dp[j-i*i]+1);
//             }
//         }
//         return dp[n];
//     }
// };

//二维
class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n); //#include<cmath>
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j >= i*i) {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-i*i]+1);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

// @lc code=end

