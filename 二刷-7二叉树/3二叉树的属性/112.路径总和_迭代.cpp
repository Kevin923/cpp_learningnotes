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
//迭代 前序
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

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while(!st.empty()){
            pair<TreeNode*, int> node = st.top();
            st.pop();
            if(node.first->left == nullptr && node.first->right == nullptr && targetSum == node.second){
                return true;
            }
            if(node.first->right){
                st.push(pair<TreeNode*, int>(node.first->right, node.first->right->val + node.second));
            }
            if(node.first->left){
                st.push(pair<TreeNode*, int>(node.first->left, node.first->left->val + node.second));
            }
        }
        return false;
    }
};
// @lc code=end

