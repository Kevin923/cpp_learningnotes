/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    //dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1) return len;
        int res = 0;
        vector<int> dp(len, 1);

        for(int i = 1; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    /*
                        注意这里不是比较dp[i]和dp[j]+1
                        而是取dp[j]得最大值
                    */
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > res) res = dp[i];
        }
        return res;   
    }
};
// @lc code=end

