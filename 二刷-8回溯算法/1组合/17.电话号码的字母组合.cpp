/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
   // 0-9
    string map[10]={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    string path;
    void back(string& str, int index){
        if(index == str.size()){
            res.push_back(path);
            return;
        }

        int pos = str[index] - '0';
        for(int i = 0; i < map[pos].size(); i++){
            path += map[pos][i];
            back(str, index + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return res;
        }
        back(digits, 0);
        return res;
    }
};
// @lc code=end

