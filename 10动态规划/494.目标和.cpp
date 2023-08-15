/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(abs(target)>sum) return 0;
        if((sum+target)%2==1) return 0;
        int bagweight=(sum+target)/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(bagweight+1,0));
        dp[0][0]=1;
        for(int i=1; i<=nums.size(); i++){
            for(int j=0; j<=bagweight; j++){
                if(j<nums[i-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[nums.size()][bagweight];

    }
};
// @lc code=end

