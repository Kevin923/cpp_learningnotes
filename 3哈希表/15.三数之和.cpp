/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {  //难 哈希和双指针 看了视频
public:
//双指针法
    vector<vector<int>> threeSum(vector<int>& nums) {
        int res=0;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return ans;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left=i+1;
            int right=nums.size()-1;
            while(right>left){
                if(nums[i]+nums[left]+nums[right]>0) right--;  //a+b+c=0
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else{
                    ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    
                    //对 b和c去重
                    while( right>left && nums[right]==nums[right-1]) right--;
                    while(right>left && nums[left]==nums[left+1]) left++;
                    //双指针收缩
                    right--;
                    left++;
                }
            }
        }
        return ans;
    }



};



// @lc code=end

