/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    // struct TreeNode{
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    // };
    vector<vector<int>> res;
    vector<int> row;
    void traversal(TreeNode* root, int count){
        row.push_back(root->val);
        if(!root->left && !root->right && count == 0){
            res.push_back(row);
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            return;
        }

        //单层逻辑
        if(root->left){
            //row.push_back(root->left->val);
            traversal(root->left, count - root->left->val);
            row.pop_back();
        }
        if(root->right){
            //row.push_back(root->right->val);
            traversal(root->right, count - root->right->val);
            row.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        row.clear();
        if(root == nullptr) return {};
        traversal(root, targetSum - root->val);
        return res;
    }
};
// @lc code=end

