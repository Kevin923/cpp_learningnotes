/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        vector<int> res=robTree(root);
        return max(res[0], res[1]);
    }

    //后续遍历  vector  0：不偷  1：偷
    vector<int> robTree(TreeNode* cur){
        if(cur==NULL) return {0,0};
        vector<int> left=robTree(cur->left);
        vector<int> right=robTree(cur->right);

        //偷当前父节点， 那么就不能偷左右孩子
        int val1=cur->val+left[0]+right[0];

        //不偷当前父节点，就考虑偷或者不偷左右孩子 取两者之间的最大值
        int val2=max(left[0],left[1])+max(right[0],right[1]);

        return {val2, val1};
    }
};
// @lc code=end

