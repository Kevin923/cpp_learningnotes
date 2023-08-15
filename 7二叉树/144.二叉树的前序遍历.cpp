/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <stack>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
// };

//递归
// class Solution {
// public:
//     void preorder(TreeNode* cur,vector<int> &v){
//         if(cur==nullptr){
//             return;
//         }
//         v.push_back(cur->val);
//         preorder(cur->left,v);
//         preorder(cur->right,v);

//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         preorder(root,res);
//         return res;
//     }
// };

//非递归
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return {};
        stack<TreeNode*> st;
        
        st.push(root);
        while(!st.empty()){
            TreeNode* tmp=st.top();
            st.pop();
            res.push_back(tmp->val);
            
            if(tmp->right) st.push(tmp->right);
            if(tmp->left)  st.push(tmp->left);
        }
        return res;
    }
};
// @lc code=end

