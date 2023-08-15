/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    void back(int row, int n, vector<string>& chess) {
        if(row == n) {
            res.push_back(chess);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(isvalid(row, i, n, chess)) {
                chess[row][i] = 'Q';
                back(row + 1, n, chess); //递归下一行
                chess[row][i] = '.'; //回溯撤销
            }
        }

        return;
    }

    bool isvalid(int row, int col, int n, vector<string>& chess) {
        //检查列
        for(int i = 0; i < row; i++) {
            if(chess[i][col] == 'Q') {
                return false;
            }
        }

        //检查45度 左斜
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(chess[i][j] == 'Q') {
                return false;
            }
        }

        //检查135度 右斜
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(chess[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> chess(n, string(n, '.'));
        back(0, n, chess);
        return res;
    }
};
// @lc code=end

