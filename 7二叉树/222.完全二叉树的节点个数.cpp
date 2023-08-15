/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
//     TreeNode(int x): val(x),left(nullptr),right(nullptr){}
//     //初始化列表
// };
class Solution {
public:
    //递归 普通二叉树
    // int countNodes(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     int leftnum=countNodes(root->left);
    //     int rightnum=countNodes(root->right);
    //     return 1+leftnum+rightnum;
    // }

    //递归 完全二叉树
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftnum=0;
        int rightnum=0;
        while(left){
            left=left->left;
            leftnum++;
        }
        while(right){
            right=right->right;
            rightnum++;
        }
        if(leftnum==rightnum){
            return pow(2,leftnum+1)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);

    }

    

    // int countNodes(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     int count=0;
    //     queue<TreeNode*> qe;
    //     qe.push(root);
    //     while(!qe.empty()){
    //         int size=qe.size();
    //         count+=size;
    //         for(int i=0; i<size; i++){
    //             TreeNode* cur=qe.front();
    //             qe.pop();
    //             if(cur->left) qe.push(cur->left);
    //             if(cur->right) qe.push(cur->right);
    //         }
    //     }
    //     return count;

    // }
};
// @lc code=end

