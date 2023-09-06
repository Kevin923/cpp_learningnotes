/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> res;
    string path = "";
    void backtracking(int leftRemain, int rightRemain, int size) {
        if(path.size() == size) {
            res.push_back(path);
            return;
        }

        //leftRemain rightRemain剩余左右括号数
        //左括号大于0 就可以选
        if(leftRemain > 0) {
            path += "(";
            backtracking(leftRemain - 1, rightRemain, size);
            path.pop_back();
        }
        //剩余右括号 比左括号多就可以选
        if(rightRemain > leftRemain) {
            path += ")";
            backtracking(leftRemain, rightRemain - 1, size);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        backtracking(n, n, n * 2);
        return res;
    }
};
// @lc code=end

