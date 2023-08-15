/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
#include <queue>
#include <stack>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode():val(0),left(nullptr),right(nullptr){}
//     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
// };
class Solution {
public:
    //递归
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root==NULL) return root;
    //     swap(root->left,root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     return root;
    // }

    //深度优先前序遍历
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root == NULL) return NULL;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* cur=st.top();
    //         st.pop();
    //         swap(cur->left,cur->right);
    //         if(cur->right) st.push(cur->right);
    //         if(cur->left)  st.push(cur->left);
    //     }
    //     return root;
    // }

    //广度优先层序遍历
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> qe;
        qe.push(root);
        while(!qe.empty()){
            int size=qe.size();
            for(int i=0;i<size;i++){
                TreeNode* cur=qe.front();
                qe.pop();
                swap(cur->left,cur->right);
                if(cur->left) qe.push(cur->left);
                if(cur->right) qe.push(cur->right);
            }
        }
        return root;
    }

};
// @lc code=end

