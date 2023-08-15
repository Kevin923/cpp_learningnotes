/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool back(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') {
                    for(char k = '1'; k <= '9'; k++) {
                        if(isvalid(i, j, k, board)) {
                            board[i][j] = k;
                            if(back(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvalid(int row, int col, char k, vector<vector<char>>& board) {
        //检查行
        //注意不是 i<col  是检查一整列 应该是 i < 9
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == k) {
                return false;
            }
        }

        //检查列
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == k) {
                return false;
            }
        }

        //检查3*3
        int row_ = (row / 3) * 3;
        int col_ = (col / 3) * 3;

        for(int i = row_; i < row_ + 3; i++) {
            for(int j = col_; j < col_ + 3; j++) {
                if(board[i][j] == k) {
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        back(board);
    }
};
// @lc code=end

