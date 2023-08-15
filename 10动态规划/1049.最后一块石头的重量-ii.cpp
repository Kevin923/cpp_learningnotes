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
        //确定dp数组以及下标的含义
        //确定递推公式
        //dp数组如何初始化
        //确定遍历顺序
        //距离推导
        vector<int> dp(15001,0);
        int sum=0;
        for(int i=0; i<stones.size(); i++){
            sum+=stones[i];
        }
        int target=sum/2; //sum/2是向下取整 sum-dp[target]一定大于dp[target]

        //遍历
        for(int i=0; i<stones.size(); i++){
            for(int j=target; j>=stones[i]; j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }

        return sum-dp[target]-dp[target];
    }
};
// @lc code=end

