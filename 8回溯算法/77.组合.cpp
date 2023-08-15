/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> row;
    void backtracking(int n, int k, int startindex){
    //回溯函数终止条件
        if(row.size()==k){
            res.push_back(row);
            return;
        }
    //单层搜索过程
        for(int i=startindex; i<=n; i++){
            row.push_back(i);
            backtracking(n, k, i+1);
            row.pop_back();
        }
        return;

    }
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        row.clear();//可以不写
        backtracking(n,k,1);
        return res;
    }
};
// @lc code=end

