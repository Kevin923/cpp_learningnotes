/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool huiwen(string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    void back(string s, int index){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(huiwen(s, index, i)){
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            }else{
                continue;
            }
            back(s, i + 1);
            path.pop_back();
        }
    }


    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        back(s, 0);
        return res;
    }
};
// @lc code=end

