/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //有两个容量m和n 正常可用三维dp数组计算
    //但dp[i][][]的值和d[i-1][][]有关 则可以降温到二维dp[][]计算，即
    //滚动数组 二维dp[i][j]的含义是：最多有i个0和j个1的strs的最大子集的大小。。
    // m个0  n个1
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(string str: strs){
            int zeros=0, ones=0;
            for(char c: str){
                if(c=='0'){
                   zeros++; 
                }
                else{
                    ones++;
                }
            }

            for(int i=m; i>=zeros; i--){
                //倒叙
                for(int j=n; j>=ones; j--){
                    dp[i][j]=max(dp[i][j],dp[i-zeros][j-ones]+1);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

