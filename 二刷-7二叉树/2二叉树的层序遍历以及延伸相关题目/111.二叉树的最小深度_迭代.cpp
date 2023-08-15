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

class Solution {
public:
    // struct TreeNode{
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    // };

    int minDepth(TreeNode* root) {
        int res = 1;
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
                if(cur->left == nullptr && cur->right ==nullptr){
                    //只有当左右孩子都为空时，说明到最低点的一层了，退出
                    return res;
                }
            }
            res++;
        }
        return res;
    }
};
// @lc code=end

