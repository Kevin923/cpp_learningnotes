/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> res;
        // set<int> s1;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         if(nums2[j]==nums1[i]){
        //             s1.insert(nums2[j]);
        //         }
        //     }
        // }
        // set<int>::iterator it=s1.begin();
        // while(it!=s1.end()){
        //     res.push_back(*it);
        //     it++;
        // }
        // return res;
        unordered_set<int> res_set;
        unordered_set<int> s1(nums1.begin(),nums1.end());
        for(auto num:nums2){
            if(s1.find(num) != s1.end()){
                res_set.insert(num);
            }
        }

        return vector<int>(res_set.begin(),res_set.end());
        

    }
};
// @lc code=end

