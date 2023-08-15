/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //数组大小200，最大元素100 所以200*100得一半取10000
        /*
        dp[j]表示 背包总容量（所能装的总重量）是j，
        放进物品后，背的最大重量为dp[j]。
        */

        vector<int> dp(10001, 0);

        int sum = 0;
        for(auto i: nums) {
            sum += i;
        }

        if(sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if(dp[target] == target) {
            return true;
        }

        return false;
    }
};
// @lc code=end

