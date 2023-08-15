/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int len=nums.size();
        vector<int> dp(len, 1);
        int res=0;
        //dp[i]表示i之前的包括以nums[i]为结尾的最
        //长递增子序列长度
        for(int i=1; i<len; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    //不是单纯的比较dp[i]和dp[j]+1的大小
                    //而是要取最大的dp[j]+1；
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=dp[i]>res?dp[i]:res;
        }
        return res;
    }
};
// @lc code=end

