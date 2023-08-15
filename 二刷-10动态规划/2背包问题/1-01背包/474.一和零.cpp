/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //遍历物品
        //dp[i][j]:最多有i个0和j个1的strs的最大子集的大小为dp[i][j]。
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string str: strs) {
            int zero = 0;
            int one = 0;
            for(char c: str) {
                if(c == '1') {
                    one++;
                }
                else {
                    zero++;
                }
            }
            //遍历背包 二维度背包 倒序遍历
            for(int i = m; i >= zero; i--) {
                for(int j = n; j >= one; j--) {
                   dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

