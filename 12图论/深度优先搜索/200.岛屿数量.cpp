/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
//深搜、广搜、并查集都能做
    int dird[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>> qe;
        qe.push({x, y});
        visited[x][y] = true;
        while(!qe.empty()) {
            pair<int, int> cur = qe.front();
            qe.pop();
            int curx = cur.first;
            int cury = cur.second;
            for(int i = 0; i < 4; i++) {
                int nextx = curx + dird[i][0];
                int nexty = cury + dird[i][1];
                if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
                if(visited[nextx][nexty] == false && grid[nextx][nexty] == '1') {
                    qe.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                }
            }
        }


    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == false && grid[i][j] == '1') {
                    res++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }   
};
// @lc code=end

