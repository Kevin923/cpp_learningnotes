#include <iostream>
using namespace std;

//二叉树
struct treeNode{
    int val;
    treeNode* left;
    treeNode* right;
    treeNode(int x):val(x),left(NULL),right(NULL){}
};