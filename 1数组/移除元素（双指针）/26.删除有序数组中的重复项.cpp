/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //双指针
        int slow=0;
        int size=nums.size();
        for(int i=1;i<size;i++)
        {
            if(nums[i]!=nums[slow]){
                nums[++slow]=nums[i];
            }
        }
        return slow+1;

    }
};
// @lc code=end

