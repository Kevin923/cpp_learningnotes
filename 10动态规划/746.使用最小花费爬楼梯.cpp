/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    //确定dp数组及下标含义
    //确定递推公式
    //dp数组初始化
    //确定遍历顺序
    //举例推导dp数组
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2; i<=cost.size(); i++){
            dp[i]=min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};
// @lc code=end

