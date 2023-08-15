/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(strs[i]);
        }

        for(auto it = map.begin(); it != map.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
// @lc code=end

