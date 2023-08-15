/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    void s_reverse(string &s,int a,int b){
        while(a<b){
            swap(s[a],s[b]);
            a++;
            b--;
        }
    }
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=(2*k)){
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if(i+k <= s.size()){
                s_reverse(s,i,i+k-1);
            }
            else{
                s_reverse(s,i,s.size()-1);
            }
        }

        return s;
    }
};
// @lc code=end

