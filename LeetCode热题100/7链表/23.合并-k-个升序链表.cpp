/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include <queue>
using namespace std;

class Solution {
public:
    // struct ListNode {
    //     int val;
    //     ListNode* next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode* next) : val(x), next(next) {}
    // };

    //方法三：优先队列
    class mycompare{
    public:
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val; //小顶堆
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycompare> pq;
        //[[1,4,5],[1,3,4],[2,6]]
        for(auto node: lists) {
            if(node) {
                pq.push(node); //pq: 1 1 2
            }
        }
        ListNode* newhead = new ListNode();
        ListNode* cur = newhead;
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            //例如第一个节点分别为1 3 4 但是1后面的2比 3 4也都小所以第二个节点为2 应该把他也加入优先级队列
            if(node->next){
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }
        return newhead->next;
     
    }
};
// @lc code=end

