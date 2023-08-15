/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        int res = dp[0];
        //dp[i]：包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]。
        for(int i = 1; i < len; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(dp[i] > res) res = dp[i];
        }
        return res;
    }
};
// @lc code=end

