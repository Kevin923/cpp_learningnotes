/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <vector>
using namespace std;

//位运算 异或
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
// @lc code=end

