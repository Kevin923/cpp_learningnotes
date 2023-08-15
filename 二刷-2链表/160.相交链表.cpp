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
#include <vector>
using namespace std;

// struct ListNode{
//     int val;
//     ListNode* next;
//     //初始化列表
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next){}
// };

//1.可借用set  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return nullptr;
        }
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;

        while(cur1 != cur2){
            cur1 = cur1 == nullptr ? headB : cur1->next;
            cur2 = cur2 == nullptr ? headA : cur2->next;
        }

        return cur1;
    }

};
// @lc code=end

