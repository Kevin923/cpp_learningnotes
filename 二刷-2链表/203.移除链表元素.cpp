/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        ListNode* cur = new ListNode(0);
        cur->next = head;
        ListNode* newhead = cur;
        while(cur->next){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
        //return newhead->next;
        head = newhead->next;
        delete newhead;
        return head;
    }
};
// @lc code=end

