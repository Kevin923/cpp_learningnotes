/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++){
            if(!st.empty() && s[i] == st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

