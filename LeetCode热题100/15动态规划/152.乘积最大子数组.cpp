/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
//维护两个dp 一个保存截至到i包括i的最大乘积  一个保存截至到i包括i的最小乘积
    int maxProduct(vector<int>& nums) {
        vector<int> maxdp(nums), mindp(nums);
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxdp[i] = max(maxdp[i - 1] * nums[i], max(nums[i], mindp[i - 1] * nums[i]));
            res = max(res, maxdp[i]);
            mindp[i] = min(maxdp[i - 1] * nums[i], min(nums[i], mindp[i - 1] * nums[i]));
        }
        return res;
    }
};
// @lc code=end

