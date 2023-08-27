/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
// //方法1：原地翻转 时间复杂度O(n), 空间O(1)
//     void rotate(vector<int>& nums, int k) {
//         /*
//         nums.begin()：这是指向 nums 容器中第一个元素的迭代器。
//         nums.end()：这是指向 nums 容器中最后一个元素之后位置的迭代器。
//         */
//         // 1 2 3 4 5 6 7  k = 3
//         k = k % nums.size();
//         // 7 6 5 4 3 2 1 
//         reverse(nums.begin(), nums.end());
//         //5 6 7 4 3 2 1
//         reverse(nums.begin(), nums.begin() + k);
//         // 5 6 7 1 2 3 4
//         reverse(nums.begin() + k, nums.end());  
//     }

//方法2 申请一个vector 时间On  空间On
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> help(n);
        for(int i = 0; i < n; i++) {
            help[(i + k) % n] = nums[i];
        }
        nums.assign(help.begin(), help.end());
    }
};
// @lc code=end

