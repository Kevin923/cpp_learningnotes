#include <iostream>
using namespace std;

//链表
struct ListNode{
    int val; //节点上存储的元素
    ListNode *next; //指向下一节点的指针
    ListNode(int x):val(x),next(NULL) {} //节点的构造函数
};

