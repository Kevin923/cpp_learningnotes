/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;
// struct ListNode{
//     int val;
//     ListNode* next;
//     //初始化列表
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next){}
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        //设置虚拟头节点
        ListNode* newhead=new ListNode(0);
        newhead->next = head;
        ListNode* cur = newhead;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;
            
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next=tmp1;

            cur=cur->next->next;
        }
        return newhead->next;
    }
};
// @lc code=end

