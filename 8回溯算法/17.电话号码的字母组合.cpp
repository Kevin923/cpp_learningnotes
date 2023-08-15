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
private:
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
public:
    vector<string> res;
    string row;   
    void traversal(string& digits, int index){
        if(digits.size()==index){
            res.push_back(row);
            return;
        }

        int in=digits[index]-'0';
        for(int i=0; i<map[in].size();i++){
            row.push_back(map[in][i]);
            traversal(digits,index+1);
            row.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        res.clear();
        row.clear();
        if(digits=="") return {};
        traversal(digits,0);
        return res;
    }
};
// @lc code=end

