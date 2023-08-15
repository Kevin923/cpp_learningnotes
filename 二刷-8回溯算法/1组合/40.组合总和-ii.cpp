/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void back(vector<int>& vc, int target, int sum, int index){
        if(sum > target) return;
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i = index; i < vc.size(); i++){
            if(i > index && vc[i] == vc[i - 1]){
                continue;
            }
            path.push_back(vc[i]);
            sum += vc[i];
            back(vc, target, sum, i + 1); // i+1 表示每个数字只能在每个组合使用一次
            sum -= vc[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        back(candidates, target, 0, 0);
        return res;
    }
};
// @lc code=end

