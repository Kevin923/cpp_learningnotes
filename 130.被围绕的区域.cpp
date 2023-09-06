/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public: 
    int dirt[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = 'A';
        for(int i = 0; i < 4; i++) {
            int nextx = x + dirt[i][0];
            int nexty = y + dirt[i][1];
            if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()) {
                continue;
            } 
            if(board[nextx][nexty] == 'O') {
                dfs(board, nextx, nexty);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if(board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if(board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'A') board[i][j] = 'O';

            }
        }

    }
};
// @lc code=end

