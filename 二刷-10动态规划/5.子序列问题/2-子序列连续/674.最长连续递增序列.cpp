/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    // int findLengthOfLCIS(vector<int>& nums) {
    //     int res = 1;
    //     int maxres = 0;
    //     for(int i = 1; i < nums.size(); i++) {
    //         if(nums[i] > nums[i - 1]) {
    //             res++;
    //         }
    //         else{
    //             maxres = max(res, maxres);
    //             res = 1;
    //         }
    //     }
    //     return maxres > res ? maxres : res;
    // }
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        vector<int> dp(len, 1);
        dp[0] = 1;
        int res = 0;
        for(int i = 1; i < len; i++) {
            if(nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            if(dp[i] > res) res = dp[i];
        }
        return res;
    }
};
// @lc code=end

