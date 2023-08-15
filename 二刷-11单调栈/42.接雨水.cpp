/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    //单调栈
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int res = 0;
        for(int i = 1; i < height.size(); i++) {
            if(height[i] < height[st.top()]) {
                st.push(i);
            }
            else if(height[i] == height[st.top()]) {
                st.pop(); //其实这一句可以不加，效果是一样的，但处理相同的情况的思路却变了。              
                st.push(i);
            }
            else {
                while(!st.empty() && height[st.top()] < height[i]) {
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()) {
                        int h = min(height[i], height[st.top()]) - height[mid];
                        int w = i - st.top() - 1;
                        res += h * w;
                    }
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

