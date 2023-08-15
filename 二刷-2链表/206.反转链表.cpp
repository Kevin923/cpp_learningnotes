/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
#include <vector>
using  namespace std;

class Solution {
public:
    // struct ListNode{
    //     int val;
    //     ListNode *next;
    //     ListNode(int x):val(x),next(nullptr) {}
    // };

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

