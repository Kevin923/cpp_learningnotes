/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
#include <iostream>
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
    //int minval=INT_MAX;
public:
    vector<int> res;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
        
    int getMinimumDifference(TreeNode* root) {
        res.clear();
        inorder(root);
        int minval=INT_MAX;
        for(int i=1; i<res.size(); i++){
            if(res[i]-res[i-1] < minval)
                minval=res[i]-res[i-1];
        }
        return minval;
    }
};
// @lc code=end

