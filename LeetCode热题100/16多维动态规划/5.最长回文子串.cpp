/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
//双指针
    int left = 0;
    int right = 0;
    int maxlength = 0;
    void pointer(const string& s, int i, int j, int n) {
        while(i >= 0 && j < n && s[i] == s[j]) {
            if(j - i + 1 > maxlength) {
                maxlength = j - i + 1;
                left = i;
                right = j;
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); i++) {
            pointer(s, i, i, s.size());
            pointer(s, i, i + 1, s.size());
        }
        return s.substr(left, maxlength);
    }
};
// @lc code=end

