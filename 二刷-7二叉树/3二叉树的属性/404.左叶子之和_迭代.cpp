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
#include <stack>
using namespace std;

class Solution {
public:
    // struct TreeNode{
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    // };
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while(!st.empty()){
            TreeNode* tmp = st.top();
            st.pop();
            if(tmp->left != nullptr && tmp->left->left == nullptr && tmp->left->right == nullptr){
                res += tmp->left->val;
            }
            if(tmp->right) st.push(tmp->right);
            if(tmp->left) st.push(tmp->left);
        }
        return res;
    }
};
// @lc code=end

