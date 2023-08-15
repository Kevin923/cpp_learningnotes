/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        //掐头去尾 
        t.erase(t.begin()); // 注意是t.bengin  不是s.begin
        t.erase(t.end() - 1);
        if(t.find(s) != std::string::npos){
            return true;
        }
        return false;

    }
};
// @lc code=end

