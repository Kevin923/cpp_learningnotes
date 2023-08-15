/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <stack>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
private:
    TreeNode* pre=NULL;
public:

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool left=isValidBST(root->left);

        if(pre!=NULL && pre->val >= root->val) return false;
        pre=root;

        bool right=isValidBST(root->right);
        
        return left&&right;
    }

    // bool isValidBST(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     TreeNode* cur=root;
    //     while(cur!=NULL || !st.empty()){
    //         if(cur != NULL){
    //             st.push(cur);
    //             cur=cur->left;
             
    //         }
    //         else{
    //             cur=st.top();
    //             st.pop();
    //             if(pre!=NULL && pre->val>=cur->val) return false;
    //             pre=cur;
    //             cur=cur->right;
    //         }
    //     }
    //     return true;
    // }

};
// @lc code=end

