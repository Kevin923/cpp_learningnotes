/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution { //<int,int> <数组元素,下标>
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> hashmp;
        for(int i=0;i<nums.size();i++){
            auto it=hashmp.find(target-nums[i]);
            if(it != hashmp.end()){
                res.push_back(it->second);
                res.push_back(i);
                return res;
                //return {it->second, i};
            }
            hashmp.insert(pair<int,int>(nums[i],i));
            //hashmp.insert(nums[i],i);
        }
        return {};
    }
};
// @lc code=end

