/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            auto it = hash.find(target - nums[i]);
            if(it != hash.end()){
                res.push_back(i);
                res.push_back(it->second);
                return res;
            }
            hash.insert(pair<int,int>(nums[i], i));
        }
        return {};
    }
};
// @lc code=end

