/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
//剑指offer12.矩阵中的路径
    int dirt[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
    /*
    (1) 行或列索引越界 或 (2) 当前矩阵元素与目标字符不同 或 (3) 当前矩阵元素已访问过 
    */
    bool backtracking(vector<vector<char>>& board, string& word, int x, int y, int k, vector<vector<bool>>& visited) {
        if(board[x][y] != word[k] || visited[x][y]) return false;
        if(k == word.size() - 1) return true;
        
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nextx = x + dirt[i][0];
            int nexty = y + dirt[i][1];
            if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()) continue;
            if(backtracking(board, word, nextx, nexty, k + 1, visited)) {
                return true;
            }
        }
        visited[x][y] = false;

        return false;
    } 

    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>visited (m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(backtracking(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
        
    }
};
// @lc code=end

