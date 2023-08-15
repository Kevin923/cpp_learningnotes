/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> umap;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                umap[nums1[i] + nums2[j]]++;
            }
        }
        int res = 0;
        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                if(umap.find(0 - (nums3[i] + nums4[j])) != umap.end()){
                    res += umap[-(nums3[i] + nums4[j])];
                }
            }
        }
        return res;
    }
};
// @lc code=end

