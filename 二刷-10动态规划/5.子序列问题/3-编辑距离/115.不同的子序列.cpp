/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
/*
dp[i][j]：以i-1为结尾的s子序列中 出现以j-1
为结尾的t 的个数为dp[i][j]
二维数组 例如：s = rabbbit t= rabbit 
len(s) + 1行 len(t) + 1列
    0 1 2 3 4 5 6
      r a b b i t
0 r 
1 a
2 b
3 b
4 b
5 i
6 t
定义数组大小为字符串的长度加1，一方面是初始化方便，另一方面是
允许s和t存在为空串的情况
*/
    int numDistinct(string s, string t) {
    /*
    dp[i][0]=1:由于空字符串是任何字符串的子序列
    dp[0][j]=0:由于非空字符串不是空字符串的子序列
    dp[0][0]=1;
    */
        int len1 = s.size();
        int len2 = t.size();
        if(len2 > len1) return 0;
        vector<vector<uint64_t>> dp(len1 + 1, vector<uint64_t>(len2 + 1, 0));
        for(int i = 0; i <= len1; i++) {
            dp[i][0] = 1;//列
        }
        // for(int i = 1; i < len2; i++) {
        //     dp[0][i] = 0;
        // }
            
        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end

