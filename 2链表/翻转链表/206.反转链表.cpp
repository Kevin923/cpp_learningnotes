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
class Solution {
public:
    // struct ListNode{
    //     int val; //节点上存储的元素
    //     ListNode *next; //指向下一节点的指针
    //     ListNode(int x):val(x),next(nullptr) {} //节点的构造函数
    // };

    // ListNode* reverseList(ListNode* head) { //从前往后反转
    //     ListNode *tmp;
    //     ListNode *cur=head;
    //     ListNode *pre=nullptr;
    //     while(cur){
    //         tmp=cur->next;
    //         cur->next=pre;
    //         pre=cur;
    //         cur=tmp;
    //     }
    //     return pre;
    // }
        //递归写法
        ListNode* reverse(ListNode* pre,ListNode *cur)
        {
            if(cur==nullptr) return pre;
            ListNode* tmp=cur->next;
            cur->next=pre;
            return reverse(cur,tmp);
            
        }

        ListNode* reverseList(ListNode* head) {
            return reverse(nullptr,head);

    }
};
// @lc code=end

