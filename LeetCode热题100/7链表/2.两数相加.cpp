/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    // struct ListNode {
    //     int val;
    //     ListNode* next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode* next) : val(x), next(next) {}
    // };

    //好题
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newnode = new ListNode();
        ListNode* cur = newnode;
        int index = 0;
        //注意进位index最后如果不为0 而且l1 l2 都为空 要申请一个新节点保存进位
        while(l1 != nullptr || l2 != nullptr || index != 0) {
            index += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cur->next = new ListNode(index % 10);
            cur = cur->next;
            index = index / 10;

            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        return newnode->next;

    }
};
// @lc code=end

