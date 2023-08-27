/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
using namespace std;
//链表归并 自底向上 时间O(nlogn) 空间O(1) 自顶到底  时间O(nlogn) 空间O(logn)：递归函数调用
//数组归并 自底向上 时间O(nlogn) 空间O(1) 自顶到底  时间O(nlogn) 空间O(n)
//时间O(nlogn) 的排序：堆排 快排 归并

//自顶向下方法
class Solution {
public:
    // struct ListNode {
    //     int val;
    //     ListNode* next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode* next) : val(x), next(next) {}
    // };

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* mid = findMid(head);
        ListNode* righthead = mid->next;
        mid->next = nullptr; //切断中心节点
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(righthead);

        return merge(left, right);
    }

    //876.链表的中心节点
    ListNode* findMid(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //21.合并两个有序链表
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode();
        ListNode* cur = newhead;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = l1 == nullptr ? l2 : l1;

        return newhead->next;
    }
};
// @lc code=end

