/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();

        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        //初始化
        for(int i=0; i<=len1; i++){
            dp[i][0]=i;
        }
        for(int j=0; j<=len2; j++){
            dp[0][j]=j;
        }
        //如果word1[i-1] == word2[j-1]
        //则dp[i][j]=dp[i-1][j-1];
        //如果word1[i-1] != word2[j-1]
        //(1)删除word1[i-1],则dp[i][j]=dp[i-1][j]+1
        //(2)删除word2[j-1],则dp[i][j]=dp[i][j-1]+1
        //(3)替换word[i-1],则dp[i][j]=dp[i-1][j-1]+1
        //word2添加一个元素，相当于word1删除一个元素，所以情况分为以上三种
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
                }
            }
        }

        return dp[len1][len2];
    }
};
// @lc code=end

