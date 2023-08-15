/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        left + right = sum;
        left - right = target
        left = (sum + target) / 2;
        dp[j]:装满容量为j的背包，有多少种组合。套用本题即
        累加和为left，有多少种组合
        */
        int sum = 0;
        for(auto i: nums) {
            sum += i;
        }
        if(abs(target) > sum) return 0;
        //和为奇数实现不了
        if((sum + target) % 2 == 1) return 0;
        int begweight = (sum + target) / 2;
        vector<int> dp(begweight + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = begweight; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
                //二维dp：dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[begweight];
    }
};
// @lc code=end

