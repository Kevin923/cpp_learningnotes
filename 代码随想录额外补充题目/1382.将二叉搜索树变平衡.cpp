/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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
    vector<int> vc;
    //将数中值存入vector中使用前序遍历
    void prior(TreeNode* root){
        if(root == nullptr){
            return;
        }
        prior(root->left);
        vc.push_back(root->val);
        prior(root->right);
    }

    TreeNode* getbalance(vector<int>& v, int left, int right){
       if(left > right){
            return nullptr;
       }
       int mid = left + (right - left) / 2;
       TreeNode* root = new TreeNode(v[mid]);
       root->left = getbalance(v, left, mid - 1);
       root->right = getbalance(v, mid + 1, right);
       return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        prior(root);
        return getbalance(vc, 0, vc.size() - 1);
    }
};
// @lc code=end

