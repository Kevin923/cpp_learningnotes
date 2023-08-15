/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;

//dp：
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len=prices.size();
//         if(len==0) return 0;
//         vector<vector<int>> dp(len,vector<int>(2));
//         //dp[i][0]:第i天持有股票所得最多现金 （就是考虑买入股票花了多少钱）
//         //dp[i][1]:第i天不持有股票所得最多现金 （就是考虑卖出股票能赚多少钱）
//         dp[0][0]-=prices[0];
//         dp[0][1]=0;
//         for(int i=1; i<len; i++){
//             dp[i][0]=max(dp[i-1][0],-prices[i]); //前一天买，今天买 都是负数 所以取max 看哪个花的少
//             dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]); //前一天卖 和今天卖 看哪个赚的多
//         }

//         return dp[len-1][1];

//     }
// };

//贪心：
//尽可能找到左边最小值，右边最大值 得利润区间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int low=INT_MAX;
        int res=0;
        for(int i=0; i<prices.size(); i++){
            low=min(low,prices[i]);
            res=max(res,prices[i]-low);
        }

        return res;
    }
};
// @lc code=end

