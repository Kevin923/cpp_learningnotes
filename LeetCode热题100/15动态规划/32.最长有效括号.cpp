/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start

#include <string>
#include <vector>
#include <stack>
using namespace std;
//可以dp 可以栈 dp真想不到

class Solution {
public:
    //最长有效括号一定是以）结尾
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> mark(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(st.empty()) {
                    mark[i] = 1;
                }
                else{
                    st.pop();
                }
            }
        }
        // )()((()) 等价  1 0 0 1 0 0 0 0
        //将多余左括号置1
        while(!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }
        int len = 0;
        int res = 0;
        for(int i = 0; i < mark.size(); i++) {
            if(mark[i] == 1) {
                len = 0;
                continue;
            }
            len++;
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end

