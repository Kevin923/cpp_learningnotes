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

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), - 1);
        unordered_map<int, int> umap;
        stack<int> st;
        st.push(0);

        for(int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }

        for(int i = 1; i < nums2.size(); i++) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                if(umap.count(nums2[st.top()]) > 0) {
                    int index = umap[nums2[st.top()]];
                    res[index] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
   
        return res;
    }
};
// @lc code=end

