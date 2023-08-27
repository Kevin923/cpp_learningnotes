/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// struct ListNode{
//     int val;
//     ListNode* next;
//     //初始化列表
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next){}
// };

//1.可以用数组模拟，即将链表的值装入vector中，然后前后两个方向
//往中间走进行比较
//2.快慢指针
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;//用于分割链表为两个部分

        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //分割两部分；
        pre->next = nullptr;
        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(slow);
        //如果链表为奇数，cur2的长度比cur1多1，以cur1的长度进行比较
        while (cur1)
        {
            if(cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }

    //反转链表
    ListNode* reverseList(ListNode* head){
        ListNode* tmp;
        ListNode* cur = head;
        ListNode* pre = nullptr;

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

