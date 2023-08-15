/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j= nums.size()-1;
        while(i<=j)
        {
            int middle=(i+j)/2;
            if(nums[middle]<target){
                i=middle+1;
            }
            else if(nums[middle]>target){
                j=middle-1;
            }
            else if(nums[middle]==target){
                return middle;
            }
        }
        return i;

    }
};
// @lc code=end

