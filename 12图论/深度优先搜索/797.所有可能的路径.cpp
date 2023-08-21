/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    /*
    输入：graph = [[1,2],[3],[3],[]]
    输出：[[0,1,3],[0,2,3]]
    */
    void dfs(vector<vector<int>>& graph, int x) {
    // x：目前遍历的节点
    // graph：存当前的图
        if(x == graph.size() - 1) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < graph[x].size(); i++) {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0); //无论哪个节点都是从0出发
        dfs(graph, 0);
        return res;
    }
};
// @lc code=end

