/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void back(vector<int>& nums, vector<bool>& used) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        /*
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            //used[i - 1] == true，说明是进入下一层递归，去下一个数，所以是树枝上
           
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            //当前取的 candidates[i] 是从 candidates[i - 1] 回溯而来的。
            
            // 如果同一树层nums[i - 1]使用过则直接跳过
        */

        for(int i = 0; i < nums.size(); i++){
            if((i > 0 && nums[i] == nums[i - 1]) && used[i - 1] == false) {
                continue;
            } 
            if(used[i] == false){
                path.push_back(nums[i]);
                used[i] = true;
                back(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        back(nums, used);
        return res;

    }
};
// @lc code=end

