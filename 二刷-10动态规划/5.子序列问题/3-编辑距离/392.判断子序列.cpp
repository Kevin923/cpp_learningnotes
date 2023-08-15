/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //双指针
    bool isSubsequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if(len1 > len2) return false;
        int left = 0;
        int right = 0;
        while(right < len2) {
            if(s[left] == t[right]) {
                left++;
            }
            right++;
        }

        if(left == len1) {
            return true;
        }
        return false;
    }
};
// @lc code=end

