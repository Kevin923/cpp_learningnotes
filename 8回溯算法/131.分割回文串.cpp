/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void backtracking(string s, int index){
        if(index >= s.size()){
            res.push_back(path);
            return;
        } 

        for(int i=index; i<s.size(); i++){
            if(palindromic(s,index,i)){
                string str=s.substr(index, i-index+1);
                path.push_back(str);
            }
            else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
        return;
    }

    bool palindromic(string s, int start, int end){
        for(int i=start,j=end; i<j; i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        backtracking(s,0);
        return res;
    }
};
// @lc code=end

