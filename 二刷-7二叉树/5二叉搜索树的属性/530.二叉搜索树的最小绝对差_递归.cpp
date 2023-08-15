/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    //     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    // };
    TreeNode* pre = nullptr;
    int res = 100000;
    void inorder(TreeNode* root){
        if(root == nullptr) return;

        inorder(root->left);
        if(pre != nullptr){
            res = min(res, root->val - pre->val);
        }
        pre = root;

        inorder(root->right);
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
};
// @lc code=end

