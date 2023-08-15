/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>
using namespace std;

//递归版
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

    void traversal(TreeNode* root, vector<int>& path, vector<string>& res){
        path.push_back(root->val);
        //确定递归终止条件
        if(root->left == nullptr && root->right == nullptr){
            string spath;
            for(int i = 0; i < path.size() - 1; i++){
                spath += to_string(path[i]);
                spath += "->";
            }
            //添加最后一个元素
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
        }

        //确定单层递归逻辑
        if(root->left){
            traversal(root->left, path, res);
            path.pop_back();
        }
        if(root->right){
            traversal(root->right, path, res);
            path.pop_back();
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return {};
        vector<string> res;
        vector<int> path;
        traversal(root, path, res);
        return res;
    }
};
// @lc code=end

