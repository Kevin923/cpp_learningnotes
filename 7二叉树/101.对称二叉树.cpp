/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <stack>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

//栈 队列 递归
// class Solution {
// public:
//     bool compare(TreeNode* left, TreeNode* right){
//         if(left == NULL && right != NULL) return false;
//         else if(left != NULL && right == NULL) return false;
//         else if(left == NULL && right == NULL) return true;
//         else if(left->val != right->val) return false;

//         bool inside=compare(left->right, right->left);
//         bool outside=compare(left->left, right->right);
//         return inside&&outside;
//     }

//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL) return true;
//         return compare(root->left, root->right);
//     }

// };

//栈和队列
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> qe;
        qe.push(root->left);
        qe.push(root->right);

        while(!qe.empty()){
            TreeNode* leftNode=qe.front(); qe.pop();
            TreeNode* rightNode=qe.front(); qe.pop();

            if(leftNode==NULL && rightNode==NULL){
                continue;
            }

            if(leftNode==NULL || rightNode==NULL ||(leftNode->val != rightNode->val)){
                return false;
            }

            qe.push(leftNode->left);
            qe.push(rightNode->right);
            qe.push(leftNode->right);
            qe.push(rightNode->left);
        }
        return true;
    }

};
// @lc code=end

