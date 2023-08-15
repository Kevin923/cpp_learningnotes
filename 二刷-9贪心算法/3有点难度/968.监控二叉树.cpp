/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    // };
    /*
    0.无覆盖
    1.安装摄像头
    2.有覆盖
    */
    int res = 0;
    int traversal(TreeNode* root) {
        /*
        为了让摄像头数量最少，尽量让叶子节点的父节点安装摄像头，
        这样才能摄像头的数量最少，所以空节点的状态只能是有覆盖
        这样就可以在叶子节点的父节点放摄像头了。
        */
        if(root == nullptr) return 2;
  
        int left = traversal(root->left);
        int right = traversal(root->right);
        //1.左右节点都有覆盖，那么此时中间节点就应该是无覆盖的状态
        if(left == 2 && right == 2) {
            return 0;
        }

        //2.左右节点至少有一个无覆盖的情况 则中间节点（父节点）应该
        //安装摄像头
        if(left == 0 || right == 0) {
            res++;
            return 1;
        }
 
        //3.左右节点至少有一个摄像头，那么其父节点应该是2（覆盖状态）
        //其它情况前段代码均已覆盖
        if(left == 1 || right == 1) {
            return 2;
        }


        //这个return -1 逻辑不会走到这里
        return -1;

    }
    int minCameraCover(TreeNode* root) {
        res = 0;
        //4.头节点无覆盖
        if(traversal(root) == 0) {
            res++;
        }
        return res;
    }
};
// @lc code=end

