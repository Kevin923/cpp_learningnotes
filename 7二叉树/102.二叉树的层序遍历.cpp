/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode():val(0),left(nullptr),right(nullptr){}
//     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
// };
class Solution {
public:
    //可递归
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root==nullptr) return {};
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int> row;
            for(int i=0; i<size ; i++){
                TreeNode* cur=que.front();
                que.pop();
                row.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
            res.push_back(row);

        }
        return res;
    }
};
// @lc code=end

