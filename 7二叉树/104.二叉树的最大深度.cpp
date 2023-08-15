/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == NULL) return 0;
//         queue<TreeNode*> qe;
//         qe.push(root);
//         int depth=0;
//         while(!qe.empty()){
//             int size=qe.size();
//             for(int i=0;i<size;i++){
//                 TreeNode* cur=qe.front();
//                 qe.pop();
//                 if(cur->left) qe.push(cur->left);
//                 if(cur->right) qe.push(cur->right);
//             }
//             depth++;
//         }
//         return depth;
//     }
// };

//递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left1=maxDepth(root->left);
        int right1=maxDepth(root->right);

        int height=1+max(left1,right1);
        return height;
    }
};
// @lc code=end

