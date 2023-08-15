/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //不扩充nums，而是在遍历的过程中模拟走了两边nums。
        stack<int> st;
        st.push(0);
        vector<int> res(nums.size(), -1);
        //模拟走两边nums
        for(int i = 0; i < nums.size() * 2; i++) {
            while(!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }

        return res;
    }
};
// @lc code=end

