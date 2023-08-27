/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <vector>
using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

//剑指offer同
class Solution {
public:
    //复制原链表各节点 构建拼接链表
    //构建各个新节点的random指向
    //拆分链表 并返回新链表
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* cur = head;
        //1.
        while(cur) {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        //2.
        cur = head;
        while(cur) {
            if(cur->random) {
                cur->next->random = cur->random->next;
            }

            cur = cur->next->next;
        }

        //3.
        Node* res = head->next;
        Node* pre = head; //原链表
        cur = head->next; //新链表

        while(cur->next) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;

    }
    //哈希法
    /*
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while(cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while(cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return map[head];
    }
    */

};
// @lc code=end

