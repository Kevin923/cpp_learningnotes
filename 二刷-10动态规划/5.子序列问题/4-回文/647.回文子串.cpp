/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //双指针
    int doublepoint(string& s, int i, int j, int n) {
        int res = 0;
        while(i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
    
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            res += doublepoint(s, i, i, s.size());
            res += doublepoint(s, i, i + 1, s.size());
        }
        return res;
    }
};
// @lc code=end

