/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

#include<iostream>
#include <vector>
using namespace std;

class Solution {  //滑动窗口
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int distance=0;
        int mini=INT32_MAX;
        while(j<nums.size())
        {
            sum+=nums[j];

            while(sum>=target)
            {
                distance=(j-i+1);
                mini=mini < distance ? mini:distance;
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return mini == INT32_MAX ? 0 : mini;
    }
};

//卡尔
// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int result = INT32_MAX;
//         int sum = 0; // 滑动窗口数值之和
//         int i = 0; // 滑动窗口起始位置
//         int subLength = 0; // 滑动窗口的长度
//         for (int j = 0; j < nums.size(); j++) {
//             sum += nums[j];
//             // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
//             while (sum >= s) {
//                 subLength = (j - i + 1); // 取子序列的长度
//                 result = result < subLength ? result : subLength;
//                 sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
//             }
//         }
//         // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
//         return result == INT32_MAX ? 0 : result;
//     }
// };
// @lc code=end

