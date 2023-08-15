/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.empty() || s[i]!=st.top()){
                //  ||运算符左侧为真，则右边不被检查
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;

        // stack<char> st;
        // for (char s1 : s) {
        //     if (st.empty() || s1 != st.top()) {
        //         st.push(s1);
        //     } else {
        //         st.pop(); // s 与 st.top()相等的情况
        //     }
        // }
        // string result = "";
        // while (!st.empty()) { // 将栈中元素放到result字符串汇总
        //     result += st.top();
        //     st.pop();
        // }
        // reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        // return result;
    }
};
// @lc code=end

