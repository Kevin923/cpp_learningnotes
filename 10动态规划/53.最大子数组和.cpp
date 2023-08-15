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
//此题之前做过可用贪心，本次用dp解决
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+1,0);
        int res=-10000;
        for(int i=1; i<=nums.size(); i++){
            dp[i]=max(dp[i-1]+nums[i-1],nums[i-1]);
            if(res<dp[i]){
                res=dp[i];
            }
        }
        return res;
    }
};
// @lc code=end

