/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
//    struct TreeNode{
//         int val;
//         TreeNode* left;
//         TreeNode* right;
//         TreeNode() : val(0), left(nullptr), right(nullptr) {}
//         TreeNode(int x):val(x),left(nullptr),right(nullptr){}
//     };
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val){
            return root;
        }

        //单层逻辑
        TreeNode* node = nullptr;
        if(val > root->val){
            node = searchBST(root->right, val);
        }
        if(val < root->val){
            node = searchBST(root->left, val);
        }

        return node;
    }
};
// @lc code=end

