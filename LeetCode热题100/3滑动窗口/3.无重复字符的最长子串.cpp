/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> uset;
        int left = 0; //始终为滑动窗口左边第一个值
        int res = 0;
        //滑动窗口 + 哈希
        for(int i = 0; i < s.size(); i++) {
            //abcdb 遇见b时就应该剔除set里的b，从头开剔除
            //所以应该用while 如果用if 只能剔除a
            while(uset.find(s[i]) != uset.end()) {
                uset.erase(s[left]);
                left++;
            }
            uset.insert(s[i]);
            res = max(res, i - left + 1);
        }
        return res;
    }
};
// @lc code=end

