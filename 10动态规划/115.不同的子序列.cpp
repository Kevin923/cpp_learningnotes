/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        int res=0;
        vector<vector<uint64_t>> dp(lens + 1, vector<uint64_t>(lent + 1,0));
        //dp[i][j]：以i-1为结尾的s子序列中
        //出现以j-1为结尾的t的个数为dp[i][j]。

        //初始化
        //dp[i][0]=1:由于空字符串是任何字符串的子序列
        //dp[0][j]=0:由于非空字符串不是空字符串的子序列
        //dp[0][0]=1;
        for(int i=0; i<=lens; i++){
            dp[i][0]=1;
        }

        for(int i=1; i<=lens; i++){
            for(int j=1; j<=lent; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];   
                }
            }
        }

        return dp[lens][lent];
    }
};
// @lc code=end

