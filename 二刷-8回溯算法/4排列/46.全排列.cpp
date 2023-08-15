/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void back(vector<int>& nums, vector<bool>& used) {
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true){
                continue;
            }
            else{
                path.push_back(nums[i]);
                used[i] = true;
                back(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        back(nums, used);
        return res;
    }
};
// @lc code=end

