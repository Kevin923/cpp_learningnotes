/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

//暴力双层for循环O(n)^2
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int> res(nums.size(), 0);
//         for(int i=0; i<nums.size(); i++){
//             for(int j=0; j<nums.size(); j++){
//                 if(nums[j]<nums[i]){
//                     res[i]++;
//                 }
//             }
//         }
//         return res;
//     }
// };

//哈希
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res=nums;
        //学会使用数组当作哈希表
        sort(res.begin(), res.end());
        //进行排序，存进哈希表中，key为值，value为其下标，从后向前存储
        //其value值就是比他小的元素的个数
        int hash[101];
        for(int i = res.size()-1; i >= 0; i--){
            hash[res[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            res[i] = hash[nums[i]];
        }
        return res;
    }
};

// @lc code=end

