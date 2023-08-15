/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
#include <queue>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
// };

class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root) {
        //确定终止条件
        if(root == NULL) return 0;
        //if(root->left==NULL && root->right==NULL) return 0;

        //确定单层迭代逻辑   
        int getleft=sumOfLeftLeaves(root->left);
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
            getleft = root->left->val;
        }

        int getright=sumOfLeftLeaves(root->right);
        
        int sum=getleft + getright;
        return sum;
    }

    
};


// class Solution {
// public:

//     int sumOfLeftLeaves(TreeNode* root) {
//         int res=0;
//         if(root == NULL) return res;
//         queue<TreeNode*> qe;
//         qe.push(root);
//         while(!qe.empty()){
//             int size=qe.size();
//             for(int i=0; i<size; i++){
//                 TreeNode* cur=qe.front();
//                 qe.pop();
//                 if(cur->left) {
//                     qe.push(cur->left);
//                     if(cur->left->left==NULL && cur->left->right==NULL){
//                         res+=cur->left->val;
//                     }
//                 }
//                 if(cur->right){
//                     qe.push(cur->right);
//                 }
//             }
//         }
//         return res;
//     }
// };
// @lc code=end

