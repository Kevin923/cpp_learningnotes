/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> umap;
        for(auto i : nums1){
            umap[i]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            if(umap[nums2[i]] > 0){
                res.push_back(nums2[i]);
                umap[nums2[i]]--;
            }
        }
        return res;
    }
};
// @lc code=end

