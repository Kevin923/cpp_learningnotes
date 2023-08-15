/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
 */
#include <iostream>
using namespace std;

// struct ListNode{
//     int val; //节点上存储的元素
//     ListNode *next; //指向下一节点的指针
//     ListNode(int x):val(x),next(NULL) {} //节点的构造函数
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead= new ListNode(0);
        newhead->next=head;
        ListNode* cur=newhead;
        while(cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;
            }
            else{
                cur=cur->next;
            }
        }
        head=newhead->next;
        delete newhead;
        return head;
    }
};
// @lc code=end

