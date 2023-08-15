/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
#include <queue>
using namespace std;

// struct TreeNode{    
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x): val(x),left(nullptr),right(nullptr){}
//     //初始化列表
// };

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> qe;
        qe.push(root);
        vector<int> res;
        while(!qe.empty()){
            int size=qe.size();
            vector<int> row;
            for(int i=0;i<size; i++){
                TreeNode* cur=qe.front();
                qe.pop();
                row.push_back(cur->val);
                if(cur->left) qe.push(cur->left);
                if(cur->right) qe.push(cur->right);
            }
            int max=*max_element(row.begin(),row.end());
            res.push_back(max);
        }
        return res;

    }
};
// @lc code=end

