/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
//     TreeNode(int x): val(x),left(nullptr),right(nullptr){}
//     //初始化列表
// };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> qe;
        vector<double> res;
        qe.push(root);
        while(!qe.empty()){
            int size=qe.size();
            vector<double> row;
            for(int i=0;i<size;i++){
                TreeNode* cur=qe.front();
                qe.pop();
                row.push_back(cur->val);
                if(cur->left) qe.push(cur->left);
                if(cur->right) qe.push(cur->right);
                
            }
            double sum=0;
            for(int j=0;j<row.size();j++){
                sum+=row[j];
            }
            res.push_back(sum/row.size());
        }
        return res;
    }
};
// @lc code=end

