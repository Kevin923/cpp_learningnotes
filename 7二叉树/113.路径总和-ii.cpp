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
#include <stack>

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
// };

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path; 
    void traversal(TreeNode* root, int sum){

        if(root->left == NULL && root->right == NULL && sum==0){
            res.push_back(path);
            return;
        }
        if(root->left==NULL && root->right==NULL) return;


        if(root->left){
            path.push_back(root->left->val);
            traversal(root->left,sum - root->left->val);
            path.pop_back();
        }

        if(root->right){
            path.push_back(root->right->val);
            traversal(root->right,sum - root->right->val);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path.clear();
        if(root == NULL) return res;
        path.push_back(root->val);
        traversal(root,targetSum - root->val);
        return res;
    }
};
// @lc code=end

