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
    void getnext(int *next, string& s){
        //j前缀末尾 i后缀末尾 next[i] 截至到i（包含i）的最长相等前后缀长度

        int j = 0;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];  
            }

            if(s[i] == s[j]){
                j++;
            }

            next[i] = j;

        }
    }

    int strStr(string haystack, string needle) {
        //先求next数组 即前缀表 记录最长相等前后缀
        //前缀：以第一个字符开始不包含最后一个字符的任意连续子串
        //后缀：以最后一个字符结束不包含第一个字符的任意连续子串
        int next[needle.size()];
        getnext(next, needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
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

