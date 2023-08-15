/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
using namespace std;

// struct TreeNode{    
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x): val(x),left(nullptr),right(nullptr){}
//     //初始化列表
// };

class Solution {
public:
    int getheight(TreeNode* root){
        if(root == NULL) return 0;

        int lefthei=getheight(root->left);
        if(lefthei == -1) return -1;
        int righthei=getheight(root->right);
        if(righthei == -1) return -1;

        if(abs(lefthei - righthei) > 1) 
            return -1;
        else{
            return 1+max(lefthei, righthei);
        }

    }

    bool isBalanced(TreeNode* root) {
        return getheight(root)==-1 ? false: true;
    }
};
// @lc code=end

