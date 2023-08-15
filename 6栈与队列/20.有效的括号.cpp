/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public: 
    //三种情况：
    //1.左边有多余的左括号  (({})
    //2. 括号不匹配   ({[)})
    //3. 右边有多余的右括号  ({}))
    bool isValid(string s) {
        if(s[0]==')' || s[0]=='}' || s[0]==']')
            return false;
        if(s.size()%2 != 0)
            return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(')');
            else if(s[i]=='{') st.push('}');
            else if(s[i]=='[') st.push(']');
            else if(st.empty()|| st.top()!=s[i] ) {
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty();
    
    }
};
// @lc code=end

