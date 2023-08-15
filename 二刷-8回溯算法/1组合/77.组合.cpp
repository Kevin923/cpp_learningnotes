/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void back(int n, int k, int startindex){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = startindex; i <= n; i++){
            path.push_back(i);
            back(n, k, i + 1);
            path.pop_back();
        }
            
    }

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        back(n, k, 1);
        return res;
    }
};
// @lc code=end

