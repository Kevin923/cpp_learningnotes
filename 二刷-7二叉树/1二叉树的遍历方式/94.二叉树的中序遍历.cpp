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
    // //递归
    // void postorder(TreeNode* root, vector<int>& res){
    //     if(root == nullptr) return;
    //     postorder(root->left, res);
    //     res.push_back(root->val);
    //     postorder(root->right, res);
    //     return;
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     postorder(root, res);
    //     return res;
    // }

    //迭代
    vector<int> inorderTraversal(TreeNode* root){
        if(root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        while(cur || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                TreeNode* tmp = st.top();
                res.push_back(tmp->val);
                st.pop();
                cur = tmp->right;
            }

        }
        return res;
    }

};
// @lc code=end

