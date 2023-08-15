/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    //可动态规划，可贪心
    //计算每隔一天的利润，最后累加利润只为正数的结果，即是最大利润
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=1; i<prices.size(); i++){
            res+=max(prices[i]-prices[i-1],0);
        }
        return res;
    }
};
// @lc code=end

