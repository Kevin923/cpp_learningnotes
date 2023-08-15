/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start

// Definition for a Node.
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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
//};


class Solution {
public:
    // int maxDepth(Node* root) {
    //     if(root == NULL) return 0;
    //     queue<Node*> qe;
    //     qe.push(root);
    //     int res=0;
    //     bool flag=true;
    //     while(!qe.empty()){
    //         int size=qe.size();
    //         res++;
    //         for(int i=0; i<size; i++){
    //             Node* cur=qe.front();
    //             qe.pop();
    //             for(int j=0;j<cur->children.size();j++){
    //                 if(cur->children[j]!=NULL){   
    //                     qe.push(cur->children[j]);
    //                 }
    //             }
     
    //         }
    //     }
    //     return res;
    // }

    //递归
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int depth=0;
        for(int i=0; i<root->children.size(); i++){
            depth=max(depth,maxDepth(root->children[i]));
        }
        return depth+1;
    }
};
// @lc code=end

