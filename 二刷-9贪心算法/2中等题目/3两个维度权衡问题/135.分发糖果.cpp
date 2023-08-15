/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candysweet(ratings.size(), 1);

        //从左至右
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) {
                candysweet[i] = candysweet[i - 1] + 1;
            }
        }

        //从右至左
        for(int i = ratings.size() - 1; i >= 1; i--) {
            if(ratings[i - 1] > ratings[i]) {
                candysweet[i - 1] = max(candysweet[i] + 1, candysweet[i - 1]);
            }
        }

        int res = 0;
        for(auto i : candysweet) {
            res += i;
        }
        return res;
    }
};
// @lc code=end

