/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;

        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
            /*
            等价下面这种写法，本题其实就是递归搜索一条边的写法
            有满足的条件直接返回
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            return right 
            */

        }
        else if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p , q);
        }
        return root;
    }
};
// @lc code=end

