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

    bool traversal(TreeNode* root, int count){
        //终止条件
        if(root->left == nullptr && root->right == nullptr && count == 0){
            return true;
        }
        if(root->left == nullptr && root->right == nullptr){ //遇到叶子节点直接返回
            return false;
        }

        //单层递归逻辑

        if(root->left){
            //如果叶子节点返回true，则直接返回true
            if(traversal(root->left, count - root->left->val)){
                return true;
            }
        }

        if(root->right){
            if(traversal(root->right, count - root->right->val)){
                return true;
            }
 
        }
    
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return hasPathSum(root, targetSum - root->val);
    }
};
// @lc code=end

