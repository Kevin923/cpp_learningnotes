/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    // };

    //普通二叉树求节点的个数，也适用完全二叉树
    // int countNodes(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     int left = countNodes(root->left);
    //     int right = countNodes(root->right);
    //     return 1 + left + right;
    // }

    //完全二叉树
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftdepth = 0;
        int rightdepth = 0;
        while(left){
            left = left->left;
            leftdepth++;
        }
        while(right){
            right = right->right;
            rightdepth++;
        }

        if(leftdepth == rightdepth){
            return (2 << leftdepth) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    
    //普通话二叉树求节点数目的方式
    // int countNodes(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     int left = countNodes(root->left);
    //     int right = countNodes(root->right);
    //     return left + right + 1;
    // }

};
// @lc code=end

