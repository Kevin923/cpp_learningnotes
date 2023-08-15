/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool> used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
         
        for(int i=0; i<nums.size(); i++){
            if((i-1>=0 && nums[i]==nums[i-1]) && used[i-1]==true){
                continue;
            }
            if(used[i] == false){
                path.push_back(nums[i]);
                used[i]=true;
                backtracking(nums, used);
                used[i]=false;
                path.pop_back();
            }
        }
        return;
    }
public:
    //去重先排序 本题同一树层不可以重复，同一树枝可以重复，并需要used数组
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(),false);
        backtracking(nums, used);
        return res;
    }
};
// @lc code=end

