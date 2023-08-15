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
//深度优先先序遍历 或广度优先也可以做
class Solution {
public:
//    struct TreeNode{
//         int val;
//         TreeNode* left;
//         TreeNode* right;
//         TreeNode() : val(0), left(nullptr), right(nullptr) {}
//         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//         TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//     };
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return root;
    }
};
// @lc code=end

