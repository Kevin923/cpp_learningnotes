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

//左闭右开
class Solution {
public:
    // struct TreeNode{
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    // };
    TreeNode* traversal(vector<int>& inorder, int inorderbegin, int inorderend, vector<int>& postorder, int postorderbegin, int postorderend){
        if(postorderbegin == postorderend) return NULL;
        int rootvalue = postorder[postorderend - 1];
        TreeNode* root = new TreeNode(rootvalue);
        //遇到叶子节点返回
        if(postorderend - postorderbegin == 1) return root;

        //在中序数组中找切割点
        int cut;
        for(cut = inorderbegin; cut < inorderend; cut++){
            if(inorder[cut] == rootvalue){
                break;
            }
        }

        //切割中序左右数组
        //左中序区间左闭右开[leftInorderbegin,leftInorderend)
        int leftInorderbegin = inorderbegin;
        int leftInorderend = cut;
        //右中序区间左闭右开[rightInorderbegin,rightInorderend)
        int rightInorderbegin = cut + 1;
        int rightInorderend = inorderend;

        //切割后序左右数组
        //左后序区间[leftpostorderBegin,lefttpostorderEnd)
        int leftpostorderBegin = postorderbegin;
        int lefttpostorderEnd = postorderbegin + leftInorderend - leftInorderbegin;
        //右后序区间[rightpostorderBegin,rightpostorderEnd)
        int rightpostorderBegin = lefttpostorderEnd;
        int rightpostorderEnd = postorderend - 1;

        root->left = traversal(inorder, leftInorderbegin, leftInorderend, postorder, leftpostorderBegin, lefttpostorderEnd);
        root->right = traversal(inorder, rightInorderbegin, rightInorderend, postorder, rightpostorderBegin, rightpostorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return nullptr;
        }
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

