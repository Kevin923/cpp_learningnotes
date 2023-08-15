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
#include <stack>
using namespace std;

class Solution {
public:
    // struct TreeNode{
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // };
    
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }else{
                TreeNode* tmp = st.top();
                st.pop();
                if(pre != nullptr && pre->val >= tmp->val){
                    return false;
                }
                pre = tmp;
                cur = tmp->right;
            }
        
        }
        return true;
    }
};
// @lc code=end

