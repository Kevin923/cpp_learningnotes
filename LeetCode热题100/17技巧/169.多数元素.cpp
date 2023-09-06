/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //摩尔投票
    int majorityElement(vector<int>& nums) {
        int res = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == res) {
                count++;
            }
            else {
                count--;
                if(count == 0) {
                    res = nums[i];
                    count = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

