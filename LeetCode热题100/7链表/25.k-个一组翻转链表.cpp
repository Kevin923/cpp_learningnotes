/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    //使用类似头插法的方法
    /*
    例如： 1-2-3-4-5 k = 3  转成3-2-1-4-5
    顶一个头newhead, pre = newhead 
    node-1-2-3-4-5
    令cur = 1
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newnode = new ListNode();
        newnode->next = head;
        ListNode* pre = newnode;

        while(1) {
            //判断剩余节点是否小k 若小于直接返回
            ListNode* last = pre;
            for(int i = 0; i < k; i++) {
                last = last->next;
                if(last == nullptr) {
                    return newnode->next;
                }
            }

            //类似头插法 每次都把cur后面的节点移到头部 即pre后面
            //每次循环中cur都不变 例如上面的1-2-3-4-5 k = 3的例子
            //第一次整个for循环结束后cur一直都是1
            ListNode* cur = pre->next;
            ListNode* tmp;
            for(int i = 0; i < k - 1; i++) {
                tmp = cur->next;
                cur->next = tmp->next; //1-3
                tmp->next = pre->next; // 2 - 1
                pre->next = tmp; //pre-2
            }
            pre = cur;
        }
    }
};
// @lc code=end

