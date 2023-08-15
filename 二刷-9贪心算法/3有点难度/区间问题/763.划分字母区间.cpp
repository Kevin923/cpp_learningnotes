/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        //记录字符出现的最远位置
        for(int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }

        int left = 0;
        int right = 0;
        vector<int> res;
        for(int i = 0; i < s.size(); i++) {
            //找到字符出现的最远边界
            right = max(right, hash[s[i] - 'a']);
            if(i == right) {
                res.push_back(right - left + 1);
                left = right + 1;
            }

        }
        return res;
    }
};
// @lc code=end

