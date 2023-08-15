/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {  //与三数之和相同 但需注意跳出条件 如target为负数的情况
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            //剪枝
            if(nums[i]>target && target>=0) 
                break;
            //去重
            if(i>0 && nums[i]==nums[i-1]) 
                continue;
            for(int j=i+1;j<nums.size();j++){
                //继续减枝
                if(nums[i]+nums[j]>target && target >= 0) break;
                //去重
                if((j>i+1) && nums[j]==nums[j-1]) continue;
               
                int left=j+1;
                int right=nums.size()-1;
                while(right>left){
                    if((long)nums[i]+nums[j]+nums[left]+nums[right] > target) right--;
                    else if((long)nums[i]+nums[j]+nums[left]+nums[right] < target) left++;
                    else{
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});

                        while(right>left && nums[right]==nums[right-1]) right--;
                        while(right>left && nums[left]==nums[left+1]) left++;

                        left++;
                        right--; 
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

