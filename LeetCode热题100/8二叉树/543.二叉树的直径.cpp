/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int res = 0;
    int traversal(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = traversal(root->left);
        int right = traversal(root->right);
        //将每个节点最大直径(左子树深度+右子树深度)当前最大值比较并取大者
        res = max(res, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //if(root->left == nullptr && root->right == nullptr) return 0;
        traversal(root);
        return res;
    }
};
// @lc code=end

