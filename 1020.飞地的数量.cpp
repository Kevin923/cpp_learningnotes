/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
#include <vector>
using namespace std;
/*
统计不靠边陆地的面积，先从四边向中间遍历，将所有靠边的陆地面积
变为海洋，再重新遍历地图，统计地图剩下的陆地面积 也就是剩下的中间不靠边陆地 
为最后答案
*/
#include <queue>
class Solution {
public:
    int count;
    int dirt[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void bfs(vector<vector<int>>& grid, int x, int y) {
        queue<pair<int, int>> qe;
        grid[x][y] = 0;
        qe.push({x, y});
        count++;
        while(!qe.empty()) {
            int curx = qe.front().first;
            int cury = qe.front().second;
            qe.pop();
            for(int i = 0; i < 4; i ++) {
                int nextx = curx + dirt[i][0];
                int nexty = cury + dirt[i][1];
                if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
                    continue;
                }
                if(grid[nextx][nexty] == 1) {
                    qe.push({nextx, nexty});
                    count++;
                    grid[nextx][nexty] = 0;
                }

            }

        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //从左右两边向中间遍历 陆地置0
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                bfs(grid, i, 0);
            }
            if(grid[i][n - 1] == 1) {
                bfs(grid, i, n - 1);
            }
        }

        //从上下两边向中间遍历 陆地置0
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1) {
                bfs(grid, 0, i);
            }
            if(grid[m - 1][i] == 1) {
                bfs(grid, m - 1, i);
            }
        }

        count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end

