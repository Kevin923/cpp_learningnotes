/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return NULL;
        int rootvalue=postorder[postorder.size()-1];
        TreeNode* root=new TreeNode(rootvalue);
        //叶子节点
        if(postorder.size() == 1) return root;

        //从中序数组中找切割节点
        int cut;
        for(cut=0; cut<inorder.size(); cut++){
            if(inorder[cut] == rootvalue)
                break;
        }

        //切割中序左数组，中序右数组 左闭右开
        vector<int> leftinorder(inorder.begin(),inorder.begin()+cut);
        vector<int> rightinorder(inorder.begin()+cut+1, inorder.end());

        //舍弃postorder最后一个元素，切割后序左数组，后序右数组，左闭右开
        postorder.resize(postorder.size()-1);
        vector<int> leftpostorder(postorder.begin(),postorder.begin()+leftinorder.size());
        vector<int> rightpostorder(postorder.begin()+leftinorder.size(),postorder.end());

        //左右递归
        root->left=traversal(leftinorder, leftpostorder);
        root->right=traversal(rightinorder, rightpostorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0) return NULL;
        return traversal(inorder, postorder);
    }
};
// @lc code=end

