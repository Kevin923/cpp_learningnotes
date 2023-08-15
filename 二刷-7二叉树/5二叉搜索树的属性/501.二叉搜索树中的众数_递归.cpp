/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> res;
    TreeNode* pre = nullptr;
    int count = 0; //当前频率
    int maxCount = 0; //最大频率

    void inorder(TreeNode* cur){
        if(cur == nullptr) return;
        inorder(cur->left);

        //第一个节点
        if(pre == nullptr){
            count = 1;
        }
        //与前一个节点相同
        else if(pre->val == cur->val){
            count++;
        }
        //与前一个节点不同
        else{
            count = 1;
        }
        pre = cur;
        if(count == maxCount){
            res.push_back(cur->val);
        }
        if(count > maxCount){
            maxCount = count;
            res.clear();
            res.push_back(cur->val);
        }

        inorder(cur->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return {root->val};
        }
        res.clear();
        count = 0;
        maxCount = 0;
        inorder(root);
        return res;
    }
};
// @lc code=end

