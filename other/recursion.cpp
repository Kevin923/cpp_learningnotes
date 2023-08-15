#include <iostream>
#include <vector>
using namespace std;

//二叉树
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    vec.push_back(cur->val);    // 中
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    traversal(root, result);
    return result;
}

void CreateTree(TreeNode& T) {  //创建二叉树
    int x;
	cout << "请按照先序遍历的顺序输入数据：";
	cin >> x;
	if (x == -1)
	{
		T = NULL;
        return;
	}
	else
	{
		T = new TreeNode();
		T.val = x;
		CreateTree(*T.left);
		CreateTree(*T.right);
	}
}

int main(){
    TreeNode *root=NULL;
    CreateTree(*root);
    vector<int> pre_result=preorderTraversal(root);
    for(auto i: pre_result){
        cout<<i<<" ";
    }
    return 0;
}