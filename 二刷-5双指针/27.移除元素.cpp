/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] != val){
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};
// @lc code=end

