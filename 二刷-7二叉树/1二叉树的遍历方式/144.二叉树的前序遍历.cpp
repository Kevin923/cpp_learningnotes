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

class Solution {
public:
    // struct TreeNode{
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    // };

    //递归版
    // vector<int> res;
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root == nullptr) return res;
    //     res.push_back(root->val);
    //     res = preorderTraversal(root->left);
    //     res = preorderTraversal(root->right);
    //     return res;
    // }

    //迭代版
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
           TreeNode* cur = st.top();
           res.push_back(cur->val);
           st.pop();
           if(cur->right) st.push(cur->right);
           if(cur->left) st.push(cur->left);
        }
        return res;
    }


};
// @lc code=end

