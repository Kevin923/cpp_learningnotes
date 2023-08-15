/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <vector>
#include <string>
#include <unordered_map> 
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {  //难看答案做的 也可用map
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>> res;
         unordered_map<string,vector<string>> M;
         for(auto str: strs){
            string tmp=str;
            sort(tmp.begin(),tmp.end());
            M[tmp].push_back(str);
         }
         for(auto it=M.begin();it!=M.end();it++){
            res.push_back(it->second);
         }
         return res;
    }
};
// @lc code=end

