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

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){}//初始化列表
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size() == 0) return NULL;
        int rootvalue=preorder[0];
        TreeNode* root=new TreeNode(rootvalue);
        if(preorder.size() == 1) return root;

        //找切割点
        int cut;
        for(cut=0; cut<inorder.size(); cut++){
            if(inorder[cut]==rootvalue)
                break;
        }

        //切割中序数组
        vector<int> leftinorder(inorder.begin(),inorder.begin()+cut);
        vector<int> rightinorder(inorder.begin()+cut+1,inorder.end());

        //切割前序数组
        preorder.erase(preorder.begin());
        vector<int> leftpreorder(preorder.begin(),preorder.begin()+leftinorder.size());
        vector<int> rightpreorder(preorder.begin()+leftinorder.size(),preorder.end());

        root->left=traversal(leftpreorder,leftinorder);
        root->right=traversal( rightpreorder,rightinorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        return traversal(preorder,inorder);
    }
};
// @lc code=end

