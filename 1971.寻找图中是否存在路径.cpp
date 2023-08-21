/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    int n = 200001;
    vector<int> father = vector<int> (n, 0);

    void init() {
        for(int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;
        father[v] = u;
    }

public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init();
        for(int i = 0; i < edges.size(); i++) {
            join(edges[i][0], edges[i][1]);
        }
        return isSame(source, destination);
    }
};
// @lc code=end

