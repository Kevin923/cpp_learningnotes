/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

//dp:
class Solution {
public:
//本题可用dp、双指针、暴力
    int countSubstrings(string s) {
        int len=s.size();
        int res=0;
        vector<vector<bool>> dp(len, vector<bool>(len,false));
        //布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）
        //的子串是否是回文子串，如果是dp[i][j]为true，否则为false。
        for(int i=len-1; i>=0; i--){
            for(int j=i; j<len; j++){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        res++;
                        dp[i][j]=true;
                    }
                    else if(dp[i+1][j-1]){
                        res++;
                        dp[i][j]=true;
                    }
                }
            }
        }
        return res;
    }
};

//双指针
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        int len=s.size();
        for(int i=0; i<len; i++){
            res+=doublepoint(s,i,i,len);
            res+=doublepoint(s,i,i+1,len);
        }
        return res;
    }

    int doublepoint(const string& s, int i, int j, int n){
        int res=0;
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
            res++;
        }
        return res;

    }
};
// @lc code=end

