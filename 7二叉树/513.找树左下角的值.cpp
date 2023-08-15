/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    //递归 求最大深度的第一个叶子节点
    int maxdepth=INT_MIN;
    int res;
    void travel(TreeNode* root, int depth){
        if(root->left==NULL && root->right==NULL){
            if(depth > maxdepth){
                maxdepth=depth;
                res=root->val;
            }   
            return;
        }

        if(root->left){
            travel(root->left,depth+1);
        }

        if(root->right){
            travel(root->right,depth+1);
        }
        //return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        travel(root,0);
        return res;
    }
};

// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> qe;
//         qe.push(root);
//         int res=0;
//         while(!qe.empty()){
//             int size=qe.size();
//             for(int i=0; i<size; i++){
//                 TreeNode* cur=qe.front();
//                 qe.pop();
//                 if(i == 0){
//                     res=cur->val;
//                 }
//                 if(cur->left){
//                     qe.push(cur->left);
//                 }
                
//                 if(cur->right) qe.push(cur->right);
        
//             }
//         }
//         return res;
//     }
// };
// @lc code=end

