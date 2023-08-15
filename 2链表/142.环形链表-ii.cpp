/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    // struct ListNode{
    //     int val;
    //     ListNode *next;
    //     ListNode(int x):val(x),next(nullptr) {}
    // };
    ListNode *detectCycle(ListNode *head) {//
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                ListNode* index1=head;
                ListNode* index2=fast;
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
// @lc code=end

