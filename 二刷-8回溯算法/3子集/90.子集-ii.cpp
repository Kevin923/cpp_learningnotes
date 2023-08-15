/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void back(vector<int>& nums, int index) {
        res.push_back(path);
        if(index >= nums.size()) {
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]){
                continue;
            }
            path.push_back(nums[i]);
            back(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        back(nums, 0);
        return res;
    }
};
// @lc code=end

