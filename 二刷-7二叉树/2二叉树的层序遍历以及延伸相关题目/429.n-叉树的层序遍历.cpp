/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // class Node {
    // public:
    //     int val;
    //     vector<Node*> children;

    //     Node() {}

    //     Node(int _val) {
    //         val = _val;
    //     }

    //     Node(int _val, vector<Node*> _children) {
    //         val = _val;
    //         children = _children;
    //     }
    // };
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> row;
            for(int i = 0; i < size; i++){
                Node* tmp = que.front();
                que.pop();
                row.push_back(tmp->val);
                if(tmp->children.size() != 0){
                    int len = tmp->children.size();
                    for(int j = 0; j < len; j++){
                        que.push(tmp->children[j]);
                    }
                }
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end

