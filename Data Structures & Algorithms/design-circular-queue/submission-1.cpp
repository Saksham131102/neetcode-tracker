class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class MyCircularQueue {
private:
    ListNode* head;
    ListNode* tail;
    int cnt;
    int maxSize;
public:
    MyCircularQueue(int k) {
        maxSize = k;
        cnt = 0;
        head = new ListNode(-1);
        tail = head;
    }
    
    bool enQueue(int value) {
        if(cnt == maxSize)
            return false;
        cnt++;
        ListNode* newNode = new ListNode(value);
        tail->next = newNode;
        tail = tail->next;
        return true;
    }
    
    bool deQueue() {
        if(cnt == 0)
            return false;
        ListNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        cnt--;
        return true;
    }
    
    int Front() {
        if(cnt == 0)
            return -1;
        return head->next->val;
    }
    
    int Rear() {
        if(cnt == 0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */