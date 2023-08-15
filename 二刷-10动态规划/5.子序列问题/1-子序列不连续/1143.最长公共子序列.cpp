/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
        dp[i][j]:长度为[0,i]的字符串text1和长度为[0,j]的字符串
        text2的最长公共子序列为dp[i][j]
        */
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        //初始化第一行
        if(text1[0] == text2[0]) {
            dp[0][0] = 1;
        }
        for(int i = 1; i < len2; i++) {
            if(text2[i] == text1[0]) {
                dp[0][i] = 1;
            }else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        //初始化第一列
        for(int i = 1; i < len1; i++) {
            if(text1[i] == text2[0]) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for(int i = 1; i < len1; i++) {
            for(int j = 1; j < len2; j++) {
                if(text2[j] == text1[i]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};
// @lc code=end

