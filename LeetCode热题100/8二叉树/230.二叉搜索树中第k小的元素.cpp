/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
#include <stack>
using namespace std;

class Solution {
public:
    // struct TreeNode{
    //     /* data */
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
    // };
    //迭代

    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur != nullptr) {
            if(cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* tmp = st.top();
                st.pop();
                k--;
                if(k == 0) {
                    return tmp->val;
                }
                
                cur = tmp->right;
            }  
        }
        return 0;

    }
};
// @lc code=end

