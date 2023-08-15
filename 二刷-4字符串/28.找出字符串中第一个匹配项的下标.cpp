/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    //求next j前缀末尾 i后缀末尾 next[i]为i之前包括i的最长相等前后缀的程度 其实就是j
    void getnext(int *next, string& s){
        int j = 0;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[j] != s[i]){
                j = next[j - 1];
            }

            if(s[j] == s[i]){
                j++;
            }
            next[i] = j;
        }

    }

    //开始匹配
    int strStr(string haystack, string needle) {
        int j = 0;
        int next[needle.size()];
        getnext(next, needle);
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && needle[j] != haystack[i]){
                j = next[j - 1];
            }

            if(haystack[i] == needle[j]){
                j++;
            }

            if(j == needle.size()){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

