/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> umap;
        stack<char> st;
        umap.insert(pair<char, char>('(', ')'));
        umap.insert(pair<char, char>('[', ']'));
        umap.insert(pair<char, char>('{', '}'));
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++){
            if(!st.empty() && umap[st.top()] == s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return true;
        }
        return false;

    }
};
// @lc code=end

