/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;

//O(n) 遍历一遍 使用两个变量记录第一个出现位置得下标和最后出现位置得下标
//O(log(n)) 二分 思想简单 细节魔鬼
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftboard = getleftboard(nums, target);
        int rightboard = getrightboard(nums, target);
        if(leftboard == -2 || rightboard == -2) return {-1, -1};
        if(rightboard - leftboard > 1) return {leftboard + 1, rightboard - 1};
        return {-1, -1};
    }
    //分别寻找target的左右边界
    //寻找右边界
    int getrightboard(vector<int>& nums, int target){
        int rightboard = -2;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] <= target){
                left = mid + 1;
                rightboard = left;
            }else{
                right = mid - 1;
            }
        }
        return rightboard;
    }

    int getleftboard(vector<int>& nums, int target){
        int leftboard = -2;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] >= target){
                right = mid - 1;
                leftboard = right;
            }
            else{
                left = mid + 1;
            }
        }
        return leftboard;
    }

};
// @lc code=end

