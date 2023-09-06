/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
#include <stack>
using namespace std;
class Solution {
public:
    // struct TreeNode{
    //     /* data */
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
    // };

    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        stack<TreeNode*> st;
        TreeNode* node = nullptr;
        st.push(root);
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if(node != nullptr) {
                node->right = cur;
                node->left = nullptr;
            }
            if(cur->right) {
                st.push(cur->right);
            } 
            if(cur->left) {
                st.push(cur->left);
            }
            node = cur;
        }
    }
};
// @lc code=end

