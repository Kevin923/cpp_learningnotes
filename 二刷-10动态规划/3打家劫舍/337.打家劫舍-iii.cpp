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

class Solution {
public:
    // struct TreeNode {
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {};
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};

    // };
    /*
    所以dp数组（dp table）以及下标的含义：
    下标为0记录不偷该节点所得到的的最大金钱，
    下标为1记录偷该节点所得到的的最大金钱。

    所以本题dp数组就是一个长度为2的数组！
    */
    //后序遍历   0：不偷  1：偷
    vector<int> robtree(TreeNode* root) {
        if(root == nullptr) {
            return {0, 0};
        }

        vector<int> left = robtree(root->left);
        vector<int> right = robtree(root->right);

        //偷该节点
        int val1 = root->val + left[0] + right[0];

        //不偷该节点
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {val2, val1};
    }

    int rob(TreeNode* root) {
        vector<int> res = robtree(root);
        return max(res[0], res[1]);
    }
};
// @lc code=end

