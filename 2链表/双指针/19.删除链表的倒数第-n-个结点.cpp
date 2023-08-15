/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
class Solution {
public:
    // struct ListNode{
    //     int val;
    //     ListNode *next;
    //     ListNode(int x):val(x),next(nullptr) {}
    // };
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        ListNode* fast=newhead;
        ListNode* slow=newhead;
        while(n-- && fast!=nullptr){
            fast=fast->next;
        }
        fast=fast->next;
        while(fast!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
       // slow->next=slow->next->next;

        ListNode* tmp=slow->next;
        slow->next=tmp->next;
        delete tmp;
        return newhead->next;
    }

};
// @lc code=end

