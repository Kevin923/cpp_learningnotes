/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
#include <queue>
#include <stack>
using namespace std;
/*
    *三种情况
    *1.两棵树相同
    *2.父亲的左子树和其相同
    *3.父亲的右子树和其相同
*/
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
    bool compare(TreeNode* father, TreeNode* son){
        if(father == nullptr && son == nullptr) return true;
        else if(father == nullptr || son == nullptr) return false;
        else if(father->val != son->val) return false;

        return compare(father->left, son->left) && compare(father->right, son->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(root == nullptr) return false;
       bool a = compare(root, subRoot);
       bool b = isSubtree(root->left, subRoot);
       bool c = isSubtree(root->right, subRoot);

       return a || b || c;
    }
};
// @lc code=end

