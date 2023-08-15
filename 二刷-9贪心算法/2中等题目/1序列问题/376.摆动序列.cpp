/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) {
            return 1;
        }
        int pre = 0;
        int cur = 0;
        int res = 1;

        for(int i = 0; i < nums.size() - 1; i++) {
            cur = nums[i + 1] - nums[i];
            //记录峰值
            if((pre >= 0 && cur < 0) || (pre <= 0 && cur > 0)) {
                res++;
                pre = cur;
            }
        }
        return res;
    }
};
// @lc code=end

