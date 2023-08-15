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

//双指针（快慢指针）经典题目 快指针先走n+1, 然后同时移动快慢指针
//直到fast为空，这时slow->next就是我们要删除的元素 ，这也是为什么走 n+1
//而不是n
class Solution {
public:
    // struct ListNode{
    //     int val;
    //     ListNode *next;
    //     ListNode(int x):val(x),next(nullptr) {}
    // };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newnode = new ListNode(0);
        newnode->next = head;
        ListNode* fast = newnode;
        ListNode* slow = newnode;

        while(n-- && fast){
            fast = fast->next;
        }
        fast = fast->next;

        while(fast){
            fast = fast->next;
            slow = slow ->next;
        }

        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        return newnode->next;

    }
};
// @lc code=end

