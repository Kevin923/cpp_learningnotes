/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution { //nan
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> res;
        // unordered_map<int,int> m1;
        // for(int i: nums1){
        //     m1[nums1[i]]++;
        // }
        // for(int i: nums2){
        //     if(m1[nums2[i]]>0){
        //         res.push_back(nums2[i]);
        //         m1[nums2[i]]--; 
        //     }
        // }
        // return res;

        unordered_map<int,int> mp;
        for (int i = 0; i < nums1.size(); i++) {
           mp[nums1[i]]++; 
        }
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++) {
            if (mp[nums2[i]]>0) {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans;

        //还可以先排序 用双指针做

    }

};
// @lc code=end

