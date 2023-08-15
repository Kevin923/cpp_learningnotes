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

// struct TreeNode{    
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x): val(x),left(nullptr),right(nullptr){}
//     //初始化列表
// };

// class Solution {
// public:
//     void Calpath(TreeNode* cur, vector<int>& path, vector<string>& res){
//         //终止条件
//         path.push_back(cur->val);
//         if(cur->left==NULL && cur->right==NULL){
//             string mpath;
//             for(int i=0; i<path.size()-1; i++){
//                 mpath += to_string(path[i]);
//                 mpath += "->";
//             }
//             mpath += to_string(path[path.size()-1]);
//             res.push_back(mpath);
//             return;
//         }

//         //单层递归逻辑
//         if(cur->left){
//             Calpath(cur->left, path, res);
//             path.pop_back();
//         }
//         if(cur->right){
//             Calpath(cur->right, path, res);
//             path.pop_back();
//         }
//     }
    
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> res;
//         vector<int> path;
//         if(root == NULL) return res;
//         Calpath(root,path,res);
//         return res;
//     }
// };

//递归2 隐藏了回溯细节
class Solution {
public:
    void Calpath(TreeNode* cur, string path, vector<string>& res){
        //终止条件
        path += to_string(cur->val);
        if(cur->left==NULL && cur->right==NULL){
            res.push_back(path);
            return;
        }

        //确定单层递归逻辑
        if(cur->left){
            Calpath(cur->left, path+"->", res);
        }
        if(cur->right){
            Calpath(cur->right, path+"->", res);
        }

   
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        if(root == NULL) return res;
        Calpath(root,path,res);
        return res;
    }
};
// @lc code=end

