/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool compare(TreeNode* father, TreeNode* son){
        if(father != NULL && son == NULL) return false;
        else if(father == NULL && son != NULL) return false;
        else if(father == NULL && son == NULL) return true;
        else if(father->val != son->val) return false;

        return compare(father->left,son->left)&&compare(father->right,son->right); 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        return compare(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
      
   
};
// @lc code=end

