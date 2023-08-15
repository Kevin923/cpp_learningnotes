/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        //含首不含尾
        int res1 = steel(nums, 0, nums.size() - 2); 
        //含尾不含首
        int res2 = steel(nums, 1, nums.size() - 1);
        return max(res1, res2);
        
    }

    int steel(vector<int>& nums, int start, int end) {
        if(end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for(int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[end];
    }
};
// @lc code=end

