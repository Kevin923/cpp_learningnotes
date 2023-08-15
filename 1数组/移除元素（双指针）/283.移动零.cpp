/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // void moveZeroes(vector<int>& nums) {    //保证不了顺序
    //     int i=0;
    //     int j=nums.size()-1;
    //     int target=0;
    //     while(i<=j)
    //     {
    //         while(i<=j && nums[i]!=target)
    //         {
    //             ++i;
    //         }
    //         while(i<=j && nums[j]==target)
    //         {
    //             --j;
    //         }
    //         if(i<j)
    //         {
    //             nums[i++]=nums[j--];
    //         }
    //     }
    // }
        void moveZeroes(vector<int>& nums) {    //保证不了顺序
        int i=0;
        int target=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=target){
                nums[i++]=nums[j];
            }
        }
        for(int k=i;k<nums.size();k++)
        {   
            nums[k]=target;
        }

    }
};
// @lc code=end

