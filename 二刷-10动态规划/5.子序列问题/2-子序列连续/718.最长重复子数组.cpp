/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
//不要把此题和1143.最长公共子序列弄混 1143.的要求是子序列可以不连续
//子序列默认不连续 子数组连续
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        int res = 0;
        //初始化 
        for(int i = 0; i < len1; i++) {
            if(nums2[0] == nums1[i]) {
                dp[i][0] = 1;
                //这句不能少
                /*
                [1,2,3,2,8]
                [5,6,1,4,7]要不这种情况输出答案将为0，但是正确答案为1
                */
                res = max(res, dp[i][0]);
            }
        }
        //行
        for(int i = 0; i < len2; i++) {
            if(nums1[0] == nums2[i]) {
                dp[0][i] = 1;
                //这句不能少
                res = max(res, dp[0][i]);
            }
        }
        

        for(int i = 1; i < len1; i++) {
            for(int j = 1; j < len2; j++) {
                if(nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j- 1] + 1;
                }
                res = max(res, dp[i][j]);
            }
            
        }
        return res;
    }
};
// @lc code=end

