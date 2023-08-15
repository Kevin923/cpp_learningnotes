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
#include <algorithm>
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
    TreeNode* traversal(vector<int>& nums, int left, int right){
        if(left >= right) return NULL;

        int maxvalue=left;
        for(int i=left+1; i<nums.size(); i++){
            if(nums[i] > nums[maxvalue]){
                maxvalue = i;
            }
        }

        TreeNode* root=new TreeNode(nums[maxvalue]);

        root->left=traversal(nums, left, maxvalue);
        root->right=traversal(nums, maxvalue+1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //左闭右开
        return traversal(nums, 0, nums.size());
    }
};


// class Solution {
// public:
//     TreeNode* traversal(vector<int>& nums){
//         if(nums.size() == 0) return NULL;

//         int rootvalue=*max_element(nums.begin(), nums.end());
//         TreeNode* root=new TreeNode(rootvalue);
//         if(nums.size() == 1) return root;

//         int cut;
//         for(cut=0; cut<nums.size(); cut++){
//             if(nums[cut] == rootvalue)
//                 break;
//         }

//         if(cut==0){
//             vector<int> rightnums(nums.begin()+1,nums.end());
//             root->right=traversal(rightnums);
//         }
//         else if(cut == nums.size()-1){
//             vector<int> leftnums(nums.begin(),nums.end()-1);
//             root->left=traversal(leftnums);
//         }
//         else{
//             vector<int> leftnums(nums.begin(),nums.begin()+cut);
//             vector<int> rightnums(nums.begin()+cut+1,nums.end());
//             root->left=traversal(leftnums);
//             root->right=traversal(rightnums);
//         }

//         return root;
        
//     }

//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         if(nums.size() == 0) return NULL;
//         return traversal(nums);
//     }
// };

// @lc code=end

