/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include<iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {

//         for(int j=0;j<nums.size();j++)
//         {
//             nums[j]=pow(nums[j],2);
//         }
//         sort(nums.begin(),nums.end());
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int k=nums.size()-1;
        for(int i=0,j=nums.size()-1;i<=j;)
        {
            if(nums[i]*nums[i]<nums[j]*nums[j])
            {
                res[k--]=nums[j]*nums[j];
                j--;
            }
            else{
                res[k--]=nums[i]*nums[i];
                i++;
            }
        }
        return res;
    }
};



// @lc code=end

