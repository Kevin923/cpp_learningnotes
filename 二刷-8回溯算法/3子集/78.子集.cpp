/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void back(vector<int>& nums, int index){
        //把自己添加进去
        res.push_back(path);
        if(index >= nums.size()){
            return;
        }

        for(int i = index; i < nums.size(); i++){
            path.push_back(nums[i]);
            back(nums, i + 1);
            path.pop_back();
        }
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        back(nums, 0);
        return res;
    }   
};
// @lc code=end

