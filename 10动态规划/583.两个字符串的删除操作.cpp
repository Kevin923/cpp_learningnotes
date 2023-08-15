/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

//dp1
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int len1=word1.size();
//         int len2=word2.size();

//         vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
//         int res=0;
//         for(int i=1; i<=len1; i++){
//             for(int j=1; j<=len2; j++){
//                 if(word1[i-1] == word2[j-1]){
//                     dp[i][j]=dp[i-1][j-1]+1;
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         //本题代码与1143.最长公共子序列基本一致，只需要在最后
//         //分别减去最长公共子序列长度即可
//         return len1+len2-2*dp[len1][len2];
//     }
// };

//dp2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        //确定dp数组以及下标的含义
        //dp[i][j]:以i-1为结尾的字符串word1，以j-1为结尾的字符串word2
        //想要达到相等，所需要删除元素的最小次数。

        //2.确定递推关系 3.dp数组初始化
        //当word1[i-1]=word2[j-1]
        //dp[i][j]=dp[i-1][j-1]
        //当word1[i-1] != word2[j-1]
        //dp[i][j]=min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+2)
        //其中dp[i][j-1]+1=dp[i-1][j-1]+2（可能有点绕）
        //因为从字面上理解，dp[i][j-1]本来就不考虑word2[j-1],所以删除
        //word1[i-1],就达到了两个元素都删除的结果，即=dp[i-1][j-1]+2
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));

        //初始化
        for(int j=0; j<=len2; j++) dp[0][j]=j;
        for(int i=0; i<=len1; i++) dp[i][0]=i;


        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                }
            }
        }
        return dp[len1][len2];
   
    }
};

// @lc code=end

