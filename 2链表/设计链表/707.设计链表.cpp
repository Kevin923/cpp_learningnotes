/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct ListNode{
        int val; //节点上存储的元素
        ListNode *next; //指向下一节点的指针
        ListNode(int x) : val(x), next(nullptr) {} //节点的构造函数
    };

    MyLinkedList() {
        newhead=new ListNode(0); //虚拟头节点，不是真正的头节点
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>(size-1)){
            return -1;
        }
        ListNode* cur=newhead->next;
        while(index--)
        {
            cur=cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newnode=new ListNode(val);
        newnode->next=newhead->next;
        newhead->next=newnode;
        size++; //链表节点的个数
    }
    
    void addAtTail(int val) {
        ListNode* newnode=new ListNode(val);
        ListNode* cur=newhead;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newnode=new ListNode(val);
        if(index<0)
        {
            addAtHead(val);
        }
        else if(index==size){
            addAtTail(val);
        }
        else if(index>size){
            return;
        }
        else{
            ListNode* cur=newhead;
            while(index--)
            {
                cur=cur->next;
            }
            newnode->next=cur->next;
            cur->next=newnode;
            size++;  
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=size || index<0)
            return;
        ListNode* cur=newhead;
        while(index--){
            cur=cur->next;
        }
        ListNode* tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        size--;
    }

        // 打印链表
    void printLinkedList() {
        ListNode* cur = newhead;
        while (cur->next != nullptr) {
            std::cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int size;
    ListNode* newhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

