/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return nullptr;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* node=root->right;
                delete root;
                return node;
            }
            else if(root->right == NULL){
                TreeNode* node=root->left;
                delete root;
                return node;
            }
            else{
                TreeNode* cur=root->right;
                while(cur->left!=NULL){
                    cur=cur->left;
                }
                cur->left=root->left;
                TreeNode* tmp=root;
                root=root->right;
                delete tmp;
                return root;
            }
        }

        if(root->val < key){
            root->right=deleteNode(root->right,key);
        }
        if(root->val > key){
            root->left=deleteNode(root->left,key);
        }
        return root;
    }
};
// @lc code=end

