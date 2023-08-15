/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) return res;

            //对a去重 不能写成 nums[i] == nums[i + 1] 因为{-1，-1，2}这种情况会忽略
            //去重的意思是res里不能有重复的组，而不是一组答案里不能有重复的元素
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else{
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //对b、c去重
                    while(right > left && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(right > left && nums[right] == nums[right - 1]){
                        right--;
                    }
                    
                    //双指针收缩 继续寻找符合条件的bc
                    right--;
                    left++;

                }
            }
        }
        return res;
    }
};
// @lc code=end

