/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        stack<TreeNode*> st;
        st.push(p);
        st.push(q);
        while(!st.empty()){
            TreeNode* cur1 = st.top();
            st.pop();
            TreeNode* cur2 = st.top();
            st.pop();
            
            if(cur1 == nullptr && cur2 == nullptr){
                continue;
            }
            if(cur1 == nullptr || cur2 == nullptr || cur1->val != cur2->val){
                return false;
            }
            st.push(cur1->left);
            st.push(cur2->left);
            st.push(cur1->right);
            st.push(cur2->right);
        }
        return true;
        
    }
};
// @lc code=end

