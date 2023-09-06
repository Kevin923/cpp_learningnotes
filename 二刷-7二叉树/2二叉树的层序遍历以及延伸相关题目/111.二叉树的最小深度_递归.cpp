/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    /*
            1
             \
              2
             / \
            4   3
                /\ 
               6  5
        最小深度是1-4 这条路径 即3  不是1  
        深度是指根节点到最近的叶子节点之间的深度
    */
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(root->left == nullptr && root->right != nullptr){
            return 1 + right;
        }
        if(root->right == nullptr && root->left != nullptr){
            return 1 + left;
        }

        int res = 1 + min(left, right);
        return res;
    }
};
// @lc code=end

