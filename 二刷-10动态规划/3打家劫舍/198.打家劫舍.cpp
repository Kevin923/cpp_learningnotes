/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    /*
    dp[i]：考虑下标i（包括i）
    以内的房屋，最多可以偷窃的金额为dp[i]。
    */
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};
// @lc code=end

