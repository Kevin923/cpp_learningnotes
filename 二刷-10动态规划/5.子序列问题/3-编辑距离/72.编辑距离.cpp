/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            dp[i][j] 表示以下标i-1为结尾的字符串word1，和以下
            标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]
        */
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
       //初始化
        for(int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    //增 删 换
                    //增和删一样
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }
        return dp[len1][len2];
    }
    
};
// @lc code=end

