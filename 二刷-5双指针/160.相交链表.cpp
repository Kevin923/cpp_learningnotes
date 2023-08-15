/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode *next) : val(x), next(next) {}
    // };

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        //要么有交点跳出循环 要么没交点h1 h2 同时等于nullptr跳出循环
        while(h1 != h2){
            h1 = h1 == nullptr ? headB : h1->next;
            h2 = h2 == nullptr ? headA : h2->next;
        }

        return h1;
    }
};
// @lc code=end

