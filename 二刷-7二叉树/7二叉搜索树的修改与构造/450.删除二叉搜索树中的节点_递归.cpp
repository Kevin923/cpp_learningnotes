/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //终止条件
        if(root == nullptr) return root;

        //确定单层递归逻辑
        if(root->val == key){
            if(root->left == nullptr && root->right != nullptr){
                TreeNode* node = root->right;
                delete root;
                return node;
            }
            else if(root->left != nullptr && root->right == nullptr){
                TreeNode* node = root->left;
                delete root;
                return node;
            }
            else if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else{
                TreeNode* cur = root->right;
                while(cur->left){
                    cur = cur->left;
                }
                TreeNode* tmp = root;
                cur->left = tmp->left;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};
// @lc code=end

