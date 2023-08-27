/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
/*
先重点读懂题目中的这句该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 
的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边
不属于树中已存在的边。

这说明题目中的图原本是是一棵树，
只不过在不增加节点的情况下多加了一条边！
*/
    static const int N = 1001;
    int father[N];

    int n; // 边的数量

    void init() {
        for(int i = 0; i < n; i++) {
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

    //在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoveEdge(vector<vector<int>>& edges) {
        init();
        for(int i = 0; i < n; i++) {
            if(isSame(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

    //删一条边之后判断是不是树
    bool isTree(vector<vector<int>>& edges, int delnum) {
        init();
        for(int i = 0; i < n; i++) {
            if(i == delnum) continue;
            if(isSame(edges[i][0], edges[i][1])) {
                return false; //构成有向环了 一定不是树
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }


public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int input[N] = {0}; // 记录节点入度
        n = edges.size();
        for(int i = 0; i < n; i++) {
            input[edges[i][1]]++;
        }

        //记录入度为2的点的边
        vector<int> vec;
        //从后往前遍历
        for(int i = n - 1; i >= 0; i--) {
            if(input[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }

        //情况1和情况2
        //如果有入度为2的点 一定是两条边删除一个，看删除哪个可以构成树
        if(vec.size() > 0) {
            if(isTree(edges, vec[0])) {
                return edges[vec[0]];
            }
            else {
                return edges[vec[1]];
            }
        }

        //处理情况3，如果没有入度为2的点，那么一定是构成了有向环
        return getRemoveEdge(edges);
    
    }
};
// @lc code=end

