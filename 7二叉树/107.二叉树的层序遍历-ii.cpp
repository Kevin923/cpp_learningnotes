/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
#include <queue>
using namespace std;

// struct TreeNode{    
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x): val(x),left(nullptr),right(nullptr){}
//     //初始化列表
// };
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> qe;
        vector<vector<int>> res;
        qe.push(root);
        while(!qe.empty()){
            int size=qe.size();
            vector<int> row;
            for(int i=0;i<size;i++){
                TreeNode* cur=qe.front();
                qe.pop();
                row.push_back(cur->val);
                if(cur->left) qe.push(cur->left);
                if(cur->right) qe.push(cur->right);
                
            }
            res.push_back(row);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

