/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };
class Solution {
public:


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL && l2 != nullptr) return l2;
        if(l2 == NULL && l1 != nullptr) return l1;

        ListNode* newhead = new ListNode(0);
        
        ListNode* cur = newhead;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if(l1 == NULL && l2 != NULL) {
            cur->next = l2;
        }
        if(l2 == NULL && l1 != NULL) {
            cur->next = l1;
        }
        return newhead->next;
    }
};
// @lc code=end

