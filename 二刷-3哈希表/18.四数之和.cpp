/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > target && target >= 0){
                break;
            }
            //对a去重
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] > target && target >= 0){
                    break;
                }

                //对b去重  注意 j > i + 1
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int l = j + 1;
                int r = nums.size() - 1;
                while(l < r){
                    if((long)nums[i] + nums[j] + nums[l] + nums[r] > target){
                        r--;
                    }else if((long)nums[i] + nums[j] + nums[l] + nums[r] < target){
                        l++;
                    }else{
                        res.push_back(vector<int>{nums[i], nums[j], nums[l] ,nums[r]});
                        //对c、d 去重
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
        }

        return res;
    }
};
// @lc code=end

