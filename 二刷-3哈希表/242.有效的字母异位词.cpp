/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:

    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) return false;
        int map[26] = {0};
        for(int i = 0; i < s.size(); i++){
            map[s[i] - 'a']--;
            map[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(map[i] != 0){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

