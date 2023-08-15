/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
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

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        queue<Node*> qe;
        qe.push(root);
        while(!qe.empty()){
            int size=qe.size();
            vector<int> row;
            for(int i=0; i<size; i++){
                Node* cur=qe.front();
                qe.pop();
                row.push_back(cur->val);
                if(cur->children.size()!=0){
                    for(int i=0;i<cur->children.size();i++){
                        qe.push(cur->children[i]);
                    }
                }
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end

