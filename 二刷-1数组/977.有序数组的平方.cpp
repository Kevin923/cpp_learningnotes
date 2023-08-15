/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    //双指针 数组种数的平方后，最大的值一定在数组的两端
    //定义首尾双指针
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int k = nums.size() - 1;
        for(int i = 0, j = nums.size() - 1; i <= j; ){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                res[k--] = nums[j] * nums[j];
                j--;
            }
            else{
                res[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

