/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//自解
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res(nums1.size(), -1);
//         vector<int> tmp(nums2.size(), -1);
//         stack<int> st;
//         st.push(0);
//         for(int i=1; i<nums2.size(); i++){
//             if(nums2[i] <= nums2[st.top()]){
//                 st.push(i);
//             }
//             else{
//                 while(!st.empty() && nums2[i]>nums2[st.top()]){
//                     tmp[st.top()]=i;
//                     st.pop();
//                 }
//                 st.push(i);
//             }
//         }
//         for(int i=0; i<nums1.size(); i++){
//             for(int j=0; j<nums2.size(); j++){
//                 if(nums2[j]==nums1[i]){
//                     if(tmp[j]!= -1){
//                         res[i]=nums2[tmp[j]];
//                     }     
//                 }
//             }
//         }
//         return res;

//     }
// };

//哈希加单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        unordered_map<int,int> umap;
        stack<int> st;
        st.push(0);
        for(int i=0; i<nums1.size(); i++){
            umap[nums1[i]]=i;
        }

        for(int i=1; i<nums2.size(); i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                if(umap.find(nums2[st.top()])!=umap.end()){
                    //注意：是umap[nums2[st.top()]]，不是umap[nums2[i]]
                    int index=umap[nums2[st.top()]];
                    res[index]=nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }

        return res;

    }
};
// @lc code=end

