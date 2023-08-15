/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    void backtracking(vector<int>& vec, int sum, int target, int index){
        if(sum>target){
            return;
        }
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i=index; i<vec.size(); i++){
            path.push_back(vec[i]);
            sum+=vec[i];
            backtracking(vec, sum, target,i);
            sum-=vec[i];
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        backtracking(candidates,0,target,0);
        return res;
    }
};
// @lc code=end

