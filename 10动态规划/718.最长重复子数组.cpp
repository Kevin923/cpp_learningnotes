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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //定义二维dp数组，dp[i][j]：以下标i - 1为结尾的A，
        //和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]。
        int len1=nums1.size();
        int len2=nums2.size();
        //注意：定义vector的长度为len+1
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        dp[0][0]=0;
        int res=-1;
        //注意i<=len1 不只是<
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                res= dp[i][j]>res ? dp[i][j]:res;
            }
        }
        return res;
    }
};
// @lc code=end

