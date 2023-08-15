/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    MyLinkedList() {
        newhead = new ListNode(0); //虚拟头节点
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        ListNode* cur = newhead->next;
        while(index){
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newnode =new ListNode(val);
        newnode->next =newhead->next;
        newhead->next = newnode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = newhead;  //注意这块不能是 LisNode* cur = newhead->next;
        while(cur->next){
            cur = cur->next;
        }
        ListNode* newnode = new ListNode(val);
        cur->next = newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newnode = new ListNode(val);
        if(index < 0){
            addAtHead(val);
        }
        else if(index == size){
            addAtTail(val);
        }
        else if(index > size){
            return;
        }
        else{
            ListNode* cur = newhead;
            while(index){
                cur = cur->next;
                index--;
            }
            newnode->next = cur->next;
            cur->next = newnode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return;
        }
        ListNode* cur = newhead;
        while(index--){
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }

private:
    int size;
    ListNode* newhead; //虚拟头节点

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

