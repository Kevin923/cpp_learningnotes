/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
    }
};


// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         TreeNode* newnode=new TreeNode(val);
//         if(root == NULL){
//             return newnode;
//         }
//         TreeNode* cur=root;
//         bool flag=true;
//         while(root != NULL){
//             if(val<root->val){       
//                 if(root->left==NULL){
//                     flag=true;
//                     break;
//                 }
//                 root=root->left;
//             }
//             else if(val > root->val){
//                 if(root->right==NULL){
//                     flag=false;
//                     break;
//                 }
//                 root=root->right;
//             }
//         }
        
//         if(flag==true){
//             root->left=newnode;
//         }
//         else{
//             root->right=newnode;
//         }
//         return cur;
//     }
// };
// @lc code=end

