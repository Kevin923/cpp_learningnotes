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

//不是搜索树普通二叉树求众数的做法
#include <unordered_map>
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

    void inorder(TreeNode* root, unordered_map<int, int>& umap){
        if(root == nullptr){
            return;
        }
        umap[root->val]++;
        inorder(root->left, umap);
        inorder(root->right, umap);
        return;
    }
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> umap;
        inorder(root, umap);
        vector<pair<int, int>> vc(umap.begin(), umap.end());
        sort(vc.begin(), vc.end(), cmp);
        vector<int> res;
        res.push_back(vc[0].first);
        for(int i = 1; i < vc.size(); i++){
            if(vc[i].second == vc[0].second){
                res.push_back(vc[i].first);
            }else{
                break;
            }
        }
        return res;
    }
};
// @lc code=end

