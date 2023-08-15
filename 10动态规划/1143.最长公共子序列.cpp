/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size();
        int len2=text2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,0));
        //注意初始化过程，与718.最长重复子数组不同，本题初始化还有else条件
        //因为最长公共子序列不要求连续，并且本题定义的是以下标i结尾，不是i-1结尾
        if(text1[0] == text2[0]){
            dp[0][0]=1;
        }
        for(int i=1; i<len1; i++){
            if(text1[i]==text2[0]){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=dp[i-1][0];
            }
        }

        for(int i=1; i<len2; i++){
            if(text2[i]==text1[0]){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=dp[0][i-1];
            }
        }

        //dp[i][j]:以下标i为结尾的text1，以下标为j结尾的text2，最长
        //公共子序列
        for(int i=1; i<len1; i++){
            for(int j=1; j<len2; j++){
                if(text1[i] == text2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                } 
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                } 
               
            }
        }
        return dp[len1-1][len2-1];
    }
};
// @lc code=end

