/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    //不是单纯的组合问题，排列问题也应该用到used
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i] == false){
                path.push_back(nums[i]);
                used[i]=true;       
                backtracking(nums, used);
                used[i]=false;
                path.pop_back();
            }
            else{
                continue;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};
// @lc code=end

