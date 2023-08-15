/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
//     //初始化列表
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(nullptr), right(nullptr) {} 
// };

class Solution {
public:
    vector<int> path;
    int res = 0;
    int fun(vector<int> path){
        int sum = 0;
        for(int i = 0; i < path.size(); i++){
            sum = sum * 10 + path[i];
        }
        return sum;
    }

    void traversal(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            res += fun(path);
            return;
        }

        if(root->left != NULL){
            path.push_back(root->left->val);
            traversal(root->left);
            path.pop_back();//回溯
        }

        if(root->right != NULL){
            path.push_back(root->right->val);
            traversal(root->right);
            path.pop_back();
        }

        return;
    }

    int sumNumbers(TreeNode* root) {
        path.clear();
    
        if(root  == NULL) return 0;
        path.push_back(root->val);
        traversal(root);
        return res;
    }
};
// @lc code=end

