/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <queue>
using namespace std;

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

//有递归方法
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> qe;
        qe.push(root);
        while(!qe.empty()){
            int size=qe.size();
            for(int i=0;i<size;i++){
                Node* cur=qe.front();
                qe.pop();
                if(i<size-1){
                    cur->next=qe.front();
                }  

                if(cur->left){
                    qe.push(cur->left);
                }
                if(cur->right){
                    qe.push(cur->right);
                } 
                
            }
        }
        return root;
    }
};
// @lc code=end

