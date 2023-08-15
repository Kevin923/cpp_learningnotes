/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int maxdepth = -1;
    int res = 0;
    void traversal(TreeNode* root, int depth){
        //终止条件
        if(root->left == nullptr && root->right == nullptr){
            if(depth > maxdepth){
                maxdepth = depth;
                res = root->val;
            }
            return;  
        }

        //单层逻辑
        if(root->left != nullptr){
            depth++;
            traversal(root->left, depth);
            depth--;
        }

        if(root->right != nullptr){
            depth++;
            traversal(root->right, depth);
            depth--;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return res;
    }
};
// @lc code=end

