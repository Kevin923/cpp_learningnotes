/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int index){
        res.push_back(path);
        if(index >= nums.size()){
            return;
        }
        for(int i=index; i<nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums,0);
        return res;
    }
};
// @lc code=end

