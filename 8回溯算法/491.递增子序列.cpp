/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int index){
        if(path.size()>=2){
            res.push_back(path);
        }
        //也可以用unordered_set<int> uset,去重，但是使用数组
        //来当做哈希，可以减少时间消耗，属于是一种优化的方法。
        //每层都重新定义一个used数组，来记录当前层是否有重复元素
        int used[201]={0};
        for(int i=index; i<nums.size(); i++){
            if((!path.empty() && nums[i]<path.back()) || used[nums[i]+100]==1){
                continue;
            }
            path.push_back(nums[i]);
            used[nums[i]+100]=1;//去重，本层重复的元素不再使用，直接跳过
            backtracking(nums,i+1);
            path.pop_back();
        }
        return;
    }
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums,0);
        return res;
    }
};
// @lc code=end

