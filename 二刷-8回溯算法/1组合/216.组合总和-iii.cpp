/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void back(int n, int k, int index, int sum){
        if(path.size() == k && sum == n){
            res.push_back(path);
            return;
        }

        for(int i = index; i <= 9 && i <= n; i++) {
            path.push_back(i);
            sum += i;
            back(n, k, i + 1, sum);
            sum -= i;
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        path.clear();
        back(n, k, 1, 0);
        return res;
    }
};
// @lc code=end

