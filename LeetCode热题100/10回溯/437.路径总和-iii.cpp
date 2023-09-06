/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
class Solution {
public:
    // struct TreeNode{
    //     /* data */
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
    // };
   
    int ans = 0;
    /*一个朴素的做法是搜索以每个节点为根的（往下的）所有路径，并对路径总和为
     targetSumtargetSumtargetSum 的路径进行累加统计。*/

    //做先序遍历求累加和
    void dfs(TreeNode* root, int targetSum, long sum) {
        if(root == nullptr) return;
        sum += root->val;
        if(sum == targetSum) ans++;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);

    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        dfs(root, targetSum, 0);
        //求每个点作为根节点向下的路径和为targetsum
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};
// @lc code=end

