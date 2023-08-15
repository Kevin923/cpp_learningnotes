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
        int res = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            count += nums[i];
            //相当于不断调整最大子数组和的结束位置
            if(res < count) {
                res = count;
            }
            //子数组累加和为负数了 重新确定起点 即i + 1
            if(count < 0) {
                count = 0;
            }
        }
        return res;
    }
};
// @lc code=end

