/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int count;
    int dirt[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if(visited[x][y] == true || grid[x][y] == 0) {
            return;
        }
        visited[x][y] = true;
        count++;
        for(int i = 0; i < 4; i++) {
            int nextx = dirt[i][0] + x;
            int nexty = dirt[i][1] + y;
            if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            dfs(grid, visited, nextx, nexty);
        }
       
    }

    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    count = 0;
                    dfs(grid, visited, i, j);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};
// @lc code=end

