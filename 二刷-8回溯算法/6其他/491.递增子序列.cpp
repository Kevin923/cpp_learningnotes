/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void back(vector<int>& nums, int index){
        if(path.size() >= 2) {
            res.push_back(path);
        }
        if(index >= nums.size()) {
            return;
        }
        //每一树层都重新定义了一个set，来判断当前层元素是否被重复使用
        unordered_set<int> uset;
        for(int i = index; i < nums.size(); i++) {
            if((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            back(nums, i + 1);
            path.pop_back();
        }

        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //注意不能排序，否则就直接变成递增了
        back(nums, 0);
        return res;
    }
};
// @lc code=end

