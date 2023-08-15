/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
#include <stack>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
// };

class Solution {
public:
    //栈 前序遍历 定义pair pair<TreeNode*,int>记录节点和累加和
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        stack<pair<TreeNode*,int>> st;
        st.push(pair<TreeNode*,int>(root,root->val));
        while(!st.empty()){
            pair<TreeNode*,int> cur=st.top();
            st.pop();
            if(cur.first->left==NULL && cur.first->right==NULL && cur.second==targetSum){
                return true;
            }

            if(cur.first->right){
                st.push(pair<TreeNode*,int>(cur.first->right,cur.second+cur.first->right->val));
            }

            if(cur.first->left){
                st.push(pair<TreeNode*,int>(cur.first->left,cur.second+cur.first->left->val));
            }
        }
        return false;
    }

   //递归2
    // bool traversal(TreeNode* root, int count){
    //     if(root->left==NULL && root->right==NULL && count==0) return true;
    //     if(root->left==NULL && root->right==NULL) return false;

    //     if(root->left){
    //         if(traversal(root->left,count - root->left->val)) 
    //             return true;
    //     }

    //     if(root->right){
    //         if(traversal(root->right,count - root->right->val)) 
    //             return true;
    //     }

    //     // if(root->right){
    //     //     count=count-(root->right->val);
    //     //     if(travesal(root->right,count)) return true;
    //     //     count+=root->right->val;
    //     // }

    //     return false;
    // }

    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root == NULL) return false;
    //      return traversal(root,targetSum-(root->val));
    // }

   //递归1
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root == NULL) return false;
    
    //     if(root->left == NULL && root->right == NULL && targetSum==root->val){
    //         return true;
    //     }
    //     //if (!root->left && !root->right) return false;
        
    //     if(root->left){
    //         if(hasPathSum(root->left,targetSum-(root->val)))
    //             return true;
    //     }

    //     if(root->right){
    //         if(hasPathSum(root->right,targetSum-(root->val)))
    //             return true;
    //     }

    //     return false;
    // }
};
// @lc code=end

