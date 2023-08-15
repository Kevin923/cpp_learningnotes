/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
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
            if(i>index && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        //去重需要排序
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return res;
    }
};
// @lc code=end

