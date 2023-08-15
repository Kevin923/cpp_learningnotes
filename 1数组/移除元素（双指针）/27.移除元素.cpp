/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
//暴力法
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int size=nums.size();
//         for(int i=0;i<size;i++)
//         {
//             if(val==nums[i]){
//                 for(int j=i+1;j<size;j++){
//                     nums[j-1]=nums[j];
//                 }
//                 i--;
//                 size--;
//             }
//         }
//         return size;

//     }
// };

//双指针
//快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
//慢指针：指向更新 新数组下标的位置
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int slow=0;
//         for(int fast=0;fast<nums.size();fast++){
//             if(val!=nums[fast]){
//                 nums[slow]=nums[fast];
//                 slow++;
//             }
//         }
//         return slow;
//     }
// };

//相向双指针法 类似快速排序
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            while(left<=right && nums[left]!=val){
                ++left;
            } //从左找等于val的元素
            while(left<=right && nums[right]==val){
                right--; //从右面找不等于val
            }
            if(left<right){//将右边的元素赋值到左边
                nums[left++]=nums[right--];
            }
        }
        return left; //一定指最后元素的下一个位置 即数组的size
    }
};

// @lc code=end

