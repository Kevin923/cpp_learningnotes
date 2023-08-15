/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <queue>
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
    bool traversal(TreeNode* left, TreeNode* right){
        //确定终止条件
        if(left == nullptr && right == nullptr) return true;
        else if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left->val != right->val) return false;

        //确定单层递归的逻辑
        bool inside = traversal(left->right, right->left);
        bool outside = traversal(left->left, right->right);
        return inside && outside;

    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return traversal(root->left, root->right);
    }
};
// @lc code=end

