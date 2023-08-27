/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> father = vector<int> (2000, 0);
    void init() {
        for(int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
    }
    
    int find(int u) {
        if(u == father[u]) return u;
        else {
            return father[u] = find(father[u]);
        }
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    //插入v->u
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;
        father[v] = u;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(int i = 0; i < edges.size(); i++) {
            if(isSame(edges[i][0], edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            } else {
                join(edges[i][0], edges[i][1]);
            }
        }
        return {};
    }
};
// @lc code=end

