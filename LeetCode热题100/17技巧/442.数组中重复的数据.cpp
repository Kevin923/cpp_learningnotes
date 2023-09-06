/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end

