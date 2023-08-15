/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size() - 1;
        int i = 0;
        while(i < len){
            char tmp = s[i];
            s[i] = s[len];
            s[len] = tmp;
            i++;
            len--;
        }

    }
};
// @lc code=end

