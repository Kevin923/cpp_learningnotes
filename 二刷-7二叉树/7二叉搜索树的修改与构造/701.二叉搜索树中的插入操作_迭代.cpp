/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while(cur){
            pre = cur;
            if(cur->val > val){
                cur = cur->left;
            }
            else if(cur->val < val){
                cur = cur->right;
            }
        }
        TreeNode* node = new TreeNode(0);
        if(pre->val > val){
            pre->left = node;
            node->val = val;
        }
        else if(pre->val < val){
            pre->right = node;
            node->val = val;
        }
        return root;
    }
};
// @lc code=end

