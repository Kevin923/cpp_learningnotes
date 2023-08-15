/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

class Solution {
public:
    //递归
    int minDepth(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right!=NULL){
            return 1+minDepth(root->right);
        }
        if(root->right==NULL && root->left!=NULL){
            return 1+minDepth(root->left);
        }
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        int height=1+min(l,r);
        return height;    
    }



    // int minDepth(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     queue<TreeNode*> qe;
    //     qe.push(root);
    //     int count=0;
    //     while(!qe.empty()){
    //         int size=qe.size();
    //         for(int i=0;i<size;i++){
    //             TreeNode* cur=qe.front();
    //             qe.pop();
    //             if(cur->left){
    //                 qe.push(cur->left);
    //             }
    //             if(cur->right){
    //                 qe.push(cur->right);
    //             }
    //             if(cur->left==nullptr && cur->right==nullptr){
    //                 return count+1;
    //             }
    //         }
    //         count++;
    //     }
    //     return count;
    // }
};
// @lc code=end

