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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            //排完序最小压力都大于0 直接返回
            if(nums[i] > 0){
                break;
            }
            //对a去重
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] > 0) r--;
                else if(nums[i] + nums[l] + nums[r] < 0) l++;
                else{
                    //对b、c、去重 
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r - 1]){
                        r--;
                    }
                    l++;
                    r--;
                }
            }

        }
        return res;
    }
};
// @lc code=end

