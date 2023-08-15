/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //容量为j的背包，可以装的最大重量为dp[j]
        vector<int> dp(1501, 0);
        int sum = 0;
        for(auto i: stones) {
            sum += i;
        }
        int target = sum / 2; //向下取整
        for(int i = 0; i < stones.size(); i++) {
            for(int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        //相撞之后剩下的重量
        return sum - dp[target] - dp[target];

    }
};
// @lc code=end

