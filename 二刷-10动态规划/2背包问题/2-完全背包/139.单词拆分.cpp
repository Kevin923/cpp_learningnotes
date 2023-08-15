/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
/*
    dp[i] : 字符串长度为i的话，dp[i]为true，
    表示可以拆分为一个或多个在字典中出现的单词。
*/
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        //先遍历背包再遍历物品
        for(int i = 0; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if(uset.find(word) != uset.end() && dp[j] == true) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end

