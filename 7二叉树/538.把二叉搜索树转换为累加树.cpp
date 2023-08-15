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
#include <vector>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
private:
    int pre;
    //逆中序遍历，右中左
    void traversl(TreeNode* root){
        if(root == NULL) return;

        traversl(root->right);
        root->val+=pre;
        pre=root->val;
        traversl(root->left);

        return;
    }

public:

    TreeNode* convertBST(TreeNode* root) {
        pre=0;
        traversl(root);
        return root;
    }
};
// @lc code=end

