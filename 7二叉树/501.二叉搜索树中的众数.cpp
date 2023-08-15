/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
public:
    int count=0;
    int maxcount=0;
    vector<int> res;
    TreeNode* pre=NULL;

    void traversal(TreeNode* root){
        if(root == NULL) return;

        traversal(root->left);

        if(pre == NULL) count=1;
        else if(pre->val == root->val) count++;
        else{
            count=1;
        }
        pre=root;

        if(count == maxcount){
            res.push_back(root->val);
        }

        if(count > maxcount){
            maxcount=count;
            res.clear();
            res.push_back(root->val);
        }
        traversal(root->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        count=0;
        maxcount=0;
        res.clear();
        pre=NULL;
        traversal(root);
        return res;
    }
};
// @lc code=end

