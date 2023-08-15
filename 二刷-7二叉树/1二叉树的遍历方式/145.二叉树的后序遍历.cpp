/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    //迭代
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* tmp = st.top();
            res.push_back(tmp->val);
            st.pop();
            if(tmp->left){
                st.push(tmp->left);
            }
            if(tmp->right){
                st.push(tmp->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

