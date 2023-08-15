/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:

    //递归
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(root == NULL) return NULL;
    //     if(root->val == val) return root;

    //     if(root->val < val){
    //         return searchBST(root->right,val);
    //     }
    //     if(root->val > val){
    //         return searchBST(root->left,val);
    //     }

    //     return root;
    // }

    //迭代
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
            if(root->val > val){
                root=root->left;
            }
            else if(root->val < val){
                root=root->right;
            }
            else{
                return root;
            }
        }
        return NULL;

    }
};
// @lc code=end

