  /*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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

    //左闭右开
    TreeNode* traversal(vector<int>& num, int left, int right){
        if(left >= right) return nullptr; //数组长度为0 返回空节点

        int maxindex = left;
        for(int i = left; i < right; i++){
            if(num[i] > num[maxindex]){
                maxindex = i;
            }
        }

        TreeNode* root = new TreeNode(num[maxindex]);
        root->left = traversal(num, left, maxindex);

        root->right = traversal(num, maxindex + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
// @lc code=end

