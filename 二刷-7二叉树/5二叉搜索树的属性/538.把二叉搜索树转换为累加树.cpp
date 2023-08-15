/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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

    void reverseinorder(TreeNode* cur){
        if(cur == nullptr){
            return;
        }
        reverseinorder(cur->right);
        if(pre != nullptr){
            cur->val += pre->val;
        }
        pre = cur;

        reverseinorder(cur->left);

        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        reverseinorder(root);
        return root;
    }
};
// @lc code=end

