/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> qe;
        vector<int> row;
        qe.push(root);
        while(!qe.empty()){
            int size=qe.size();
            
            for(int i=0;i<size;i++){
                TreeNode* cur=qe.front();
                qe.pop();
                if(i== size-1){
                    row.push_back(cur->val);
                }
                if(cur->left) qe.push(cur->left);
                if(cur->right) qe.push(cur->right);
            }
        }
        return row;
    }
};
// @lc code=end

