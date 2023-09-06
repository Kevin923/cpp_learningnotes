/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
#include <vector>
using namespace std;
/*
先把外圈为0的位置全都置成1，再进行dfs
*/
class Solution {
public:
    int dirt[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int nextx = dirt[i][0] + x;
            int nexty = dirt[i][1] + y;
            if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
                continue;
            }
            if(grid[nextx][nexty] == 0){
                
                dfs(grid, nextx, nexty);
            } 
        }
    }

    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                dfs(grid, i, 0);
            }
            if(grid[i][n - 1] == 0) {
                dfs(grid, i, n - 1);
            } 
        }
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 0) {
                dfs(grid, 0, i);
            }
            if(grid[m - 1][i] == 0) {
                dfs(grid, m - 1, i);
            } 
        }


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

