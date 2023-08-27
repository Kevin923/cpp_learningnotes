/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
#include <vector>
#include <deque>
using namespace std;
// struct ListNode{
//     int val;
//     ListNode* next;
//     //初始化列表
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next){}
// };

//数组模拟加双指针 或者借助双端队列
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if(head == NULL) return;
//         vector<ListNode*> vc;
//         ListNode* cur = head;
//         while(cur){
//             vc.push_back(cur);
//             cur = cur->next;
//         }
//         cur=head;
//         int i = 1;
//         int j = vc.size() - 1;
//         int count = 0;//偶数取后面 奇数取前面
//         while(i <= j){
//             if(count % 2 == 0){
//                 cur->next = vc[j];
//                 j--;
//             }
//             else{
//                 cur->next = vc[i];
//                 i++;
//             }
//             cur = cur->next;
//             count++;
//         }
//         cur->next = nullptr;

//     }
// };

//原链表切割加反转 不借助辅助空间
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *tmp;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        //将链表切割成均等的两部分,定义快慢指针一个走一步,一个走两步
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;//断开

        ListNode* cur = head;
        head1 = head1->next;
        int count = 0;

        while(head1 && head2){
            if(count % 2 == 0){
                cur->next = head2;
                head2 = head2->next;
            }
            else{
                cur->next =head1;
                head1 = head1->next;
            }
            cur = cur->next;
            count++;
        }
        if(head1 != nullptr){
            cur->next = head1;
        }

        if(head2 != nullptr){
            cur->next =head2;
        }

    }
};
// @lc code=end

