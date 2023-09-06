/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int res = INT_MIN;
    // bool max(const int& a, const int& b) {
    //     return a > b;
    // }

    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
    
        //计算左边分支最大值，左边分支如果为负数还不如不选择
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
         //left->root->right 作为路径与已经计算过历史最大值做比较
        res = max(left + right + root->val, res);
        // 返回经过root的单边最大分支给当前root的父节点计算使用
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root);
        return res;
    }
};
// @lc code=end

