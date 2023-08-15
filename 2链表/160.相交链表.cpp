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
    // struct ListNode{
    //     int val;
    //     ListNode *next;
    //     ListNode(int x):val(x),next(nullptr) {}
    // };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //哈希
        // set<ListNode*> m_set;
        // while (headA)
        // {
        //     m_set.insert(headA);
        //     headA = headA->next;
        // }
        // while (headB)
        // {
        //     if (m_set.find(headB) != m_set.end())
        //     {
        //         return headB;
        //     }
        //     headB = headB->next;
        // }
        // return NULL;

        //双指针
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* pa=headA;
        ListNode* pb=headB;
        while(pa!=pb){
            pa=pa==NULL?headB:pa->next;
            pb=pb==NULL?headA:pb->next; 
        }
        return pa;
    }
};
// @lc code=end

