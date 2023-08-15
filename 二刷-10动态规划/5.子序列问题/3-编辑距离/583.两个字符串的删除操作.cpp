/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        //dp[i][j]：字符串a以下标i - 1为结尾，
        //字符串b以下标j - 1为结尾的最长相同连续子序列长度

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for(int i = 1; i <= len1; i++) {
            for(int j = 1;j <= len2; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return len1 + len2 - 2 * dp[len1][len2];
    }
};
// @lc code=end

