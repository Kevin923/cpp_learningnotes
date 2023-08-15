/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//递归
// class Solution {
// public:
//     void inorder(TreeNode* cur,vector<int> &v){
//         if(cur==NULL){
//             return;
//         }
//         inorder(cur->left,v);
//         v.push_back(cur->val);
//         inorder(cur->right,v);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inorder(root,res);
//         return res;
//     }
// };


//非递归 
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
         return {};
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* cur=root;
        while(cur!=NULL || !st.empty()){
            if(cur!= NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                cur=st.top();
                res.push_back(cur->val);
                st.pop();
                cur=cur->right;
            }
        }
        return res;
    }


};

// @lc code=end

