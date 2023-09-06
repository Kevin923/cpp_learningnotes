/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;
        int multi = 0;
        string res;

        for(auto str: s) {
            if(str >= '0' && str <= '9') {
                multi = multi * 10 + (str - '0'); //注意数字可能不止一位
            }
            else if(str == '[') {
                st.push({multi, res});
                multi = 0;
                res = "";
            }
            else if(str == ']') {
                string pre = st.top().second;
                int n = st.top().first;
                st.pop();
                for(int i = 0; i < n; i++) {
                    pre = pre + res;
                }
                res = pre;
                
            }
            else {
                res += str;
            }
        }
        return res;
    }
};
// @lc code=end

