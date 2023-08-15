/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& preorder, int preorderbegin, int preorderend, vector<int>& inorder, int inorderbegin, int inorderend){
        if(preorderbegin == preorderend) return nullptr;
        int rootvalue = preorder[preorderbegin];
        TreeNode* root = new TreeNode(rootvalue);

        //叶子节点
        if(preorderend - preorderbegin == 1){
            return root;
        }

        //切割中序数组
        int cur;
        for(cur = inorderbegin; cur < inorderend; cur++){
            if(inorder[cur] == rootvalue){
                break;
            }
        }

        //切割中序左右数组
        //中序左 前闭后开
        int leftinorderBegin = inorderbegin; 
        int leftinorderEnd =  cur;
        //中序右
        int rightinorderBegin = leftinorderEnd + 1;
        int rightinorderEnd = inorderend;

        //切割前序左右数组
        int leftpreorderBegin = preorderbegin + 1;
        int leftpreorderEnd = leftpreorderBegin + leftinorderEnd - leftinorderBegin;

        int rightpreorderBegin = leftpreorderEnd;
        int rightpreorderEnd = preorderend;

        root->left = traversal(preorder, leftpreorderBegin, leftpreorderEnd, inorder, leftinorderBegin, leftinorderEnd);
        root->right = traversal(preorder, rightpreorderBegin, rightpreorderEnd, inorder, rightinorderBegin, rightinorderEnd);

        return root;
    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }                                                                                              
};
// @lc code=end

