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
#include <vector>
#include <algorithm>
using namespace std;
//数组遍历法
class Solution {
public:
    // struct TreeNode{
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    // };
    void inorder(TreeNode* root, vector<int>& vec){
        if(root == nullptr){
            return;
        }
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);

        return;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> vc;
        inorder(root, vc);
        int res = 100000;
        for(int i = 1; i < vc.size(); i++){
            if(abs(vc[i] - vc[i - 1]) < res){
                res = abs(vc[i] - vc[i - 1]);
            }
        }
        return res;
    }
};
// @lc code=end

