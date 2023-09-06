#include <iostream>  
#include <vector>  
  
using namespace std;  
  
struct TreeNode {  
    int val;  
    TreeNode* left;  
    TreeNode* right;  
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
};  
  
void buildTree(vector<int>& nums, TreeNode*& root, int i = 0) {  
    if (i >= nums.size()) {  
        return;  
    }  
    TreeNode* node = new TreeNode(nums[i]);  
    root = node;  
    buildTree(nums, node->left, i * 2 + 1);  
    buildTree(nums, node->right, i * 2 + 2);  
}

//可以构建空节点
TreeNode* buildTree1(vector<int>& nums, int index) {  
    if (index >= nums.size() || nums[index] == 0) {  
        return nullptr;  
    }  
    TreeNode* node = new TreeNode(nums[index]);  
    node->left = buildTree1(nums, index * 2 + 1);  
    node->right = buildTree1(nums, index * 2 + 2);  
    return node;  
}  

void postorder(TreeNode*& root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
  
int main() {  
    vector<int> nums = {1, 2, 3, 4, 5};  
    // TreeNode* root = nullptr;  
    // buildTree(nums, root);  

    TreeNode* root = buildTree1(nums, 0);
    postorder(root); // 4 5 2 3 1
    return 0;  
}