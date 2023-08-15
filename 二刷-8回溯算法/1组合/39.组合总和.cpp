/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void back(vector<int>& vc, int target, int sum, int index) {
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i = index; i < vc.size(); i++){
            path.push_back(vc[i]);
            sum += vc[i];
            back(vc, target, sum, i); //i 表示当前元素以及当前元素之后的元素可以在每个组合中出现
            sum -= vc[i];
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        back(candidates, target, 0, 0);
        return res;
    }
};
// @lc code=end

