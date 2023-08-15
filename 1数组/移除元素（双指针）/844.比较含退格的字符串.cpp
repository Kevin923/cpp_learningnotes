/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        fun(s);
        fun(t);
        return s==t;
    }
private:
    void fun(string &st){
        int i=0;
        for(int j=0;j<st.size();j++){
            if(st[j]!='#')
            {
                st[i++]=st[j];
            }
            else {
                if(i > 0)
                    i--;
            }
        }
        st.resize(i);
    }
};

// @lc code=end

