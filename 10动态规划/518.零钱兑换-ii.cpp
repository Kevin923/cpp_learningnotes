/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // int sum=0;
        // for(int i: coins){
        //     sum+=i;
        // }
        // if(amount>sum) return 0;
        //上面注释的写法是错误的，因为相当于完全背包问题物品可以放多次
        //所以就不会有上述的情况
        vector<int> dp(amount+1,0);
        dp[0]=1;
        //先物品再背包
        for(int i=0; i<coins.size(); i++){
            for(int j=coins[i]; j<=amount; j++){
                dp[j]+=dp[j-coins[i]];
            }
        }

        return dp[amount];



    }
};
// @lc code=end

