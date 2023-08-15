/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        //初始化第一行
        if(nums1[0] == nums2[0]) {
            dp[0][0] = 1;
        }
        for(int i = 1; i < len2; i++) {
            if(nums2[i] == nums1[0]) {
                dp[0][i] = 1;
            }else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        //初始化第一列
        for(int i = 1; i < len1; i++) {
            if(nums1[i] == nums2[0]) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for(int i = 1; i < len1; i++) {
            for(int j = 1; j < len2; j++) {
                if(nums2[j] == nums1[i]) {
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

