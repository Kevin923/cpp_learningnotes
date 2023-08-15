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
#include <iostream>
#include <queue>
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
public:

    bool compare(TreeNode* p, TreeNode* q){
        if(p==NULL && q!=NULL) return false;
        else if(p != NULL && q == NULL) return false;
        else if(p==NULL && q==NULL) return true;
        else if(p->val != q->val) return false;

        bool a=compare(p->left,q->left);
        bool b=compare(p->right, q->right);
        return a&&b;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p,q);
    }



    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        queue<TreeNode*> qe;
        qe.push(p);
        qe.push(q);

        while(!qe.empty()){
            TreeNode* leftnode=qe.front(); qe.pop();
            TreeNode* rightnode=qe.front(); qe.pop();
            if(!leftnode && !rightnode)
                continue;
            
            if(!leftnode || !rightnode || (leftnode->val != rightnode->val))
                return false;

            qe.push(leftnode->left);
            qe.push(rightnode->left);
            qe.push(leftnode->right);
            qe.push(rightnode->right);
        }
        return true;             
    }
    */
};
// @lc code=end

