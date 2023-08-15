/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
private:
    //0：无覆盖
    //1：本节点有摄像头
    //2：本节点有覆盖
    int res=0;
    int travesal(TreeNode* root){
        if(root == NULL){
            return 2;
        }

        int left=travesal(root->left);
        int right=travesal(root->right);

        //情况1 左右孩子都有覆盖 本节点则为0 
        if(left==2 && right==2){
            return 0;
        }
        //3：左右孩子至少有一个无覆盖
        if(left==0 || right==0){
            res++;
            return 1; 
        }
        //2:左右孩子至少有一个摄像头
        if(left==1 || right==1){
            return 2;
        }

        return -1;
    }

public:
  
    int minCameraCover(TreeNode* root) {
        res=0;
        //需要判断头节点是不是无覆盖的情况
        if(travesal(root) == 0){
            res++;
        }
        return res;
    }
};
// @lc code=end

