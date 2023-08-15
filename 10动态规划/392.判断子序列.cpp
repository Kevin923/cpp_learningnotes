/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
//本题可用双指针来做，时间复杂度为O(n) dp时间复杂度O(m*n)
    bool isSubsequence(string s, string t) {
        if(t.size()==0 && s.size()!=0) return false;
        int lens=s.size();
        int lent=t.size();
        vector<vector<int>> dp(lent+1,vector<int>(lens+1,0));
        for(int i=1; i<=lent; i++){
            for(int j=1; j<=lens; j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    //dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                    //本题唯一与1143.最长公共子序列不同之处
                    //只需删除t元素，不用将s元素往前退，即
                    dp[i][j]=dp[i-1][j];
            
                }
            }
        }
        if(dp[lent][lens]==s.size()) 
            return true;
        else{
            return false;
        }


    }
};
// @lc code=end

