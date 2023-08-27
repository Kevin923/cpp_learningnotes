/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash1;
        unordered_map<char, char> hash2;
        for(int i = 0, j = 0; i < s.size(); i++, j++){
            if(hash1.find(s[i]) == hash1.end()){
                hash1[s[i]] = t[j];
            }

            if(hash2.find(t[j]) == hash2.end()){
                hash2[t[j]] = s[i];
            }

            if(hash1[s[i]] != t[j] || hash2[t[j]] != s[i]){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

