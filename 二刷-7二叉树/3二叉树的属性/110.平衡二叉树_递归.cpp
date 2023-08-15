/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int CalHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = CalHeight(root->left);
        if(left == -1){
            return -1;
        }

        int right = CalHeight(root->right);
        if(right == -1){
            return -1;
        }

        int res = left >= right ? left - right : right - left;
        if(res > 1){
            return -1;
        }
        else{
            return 1 + max(left, right);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int res = CalHeight(root);

        return res == -1 ? false : true;
    }
};
// @lc code=end

