struct ListNode {
    int key;
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, ListNode*> mp;
    ListNode* head;
    ListNode* tail;
    int cnt;
public:
    LRUCache(int capacity) {
        head = new ListNode(-1, -1);
        tail = head;
        cnt = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        ListNode* node = mp[key];
        if(node != tail) {
            ListNode* prevNode = node->prev;
            ListNode* nextNode = node->next;
            prevNode->next = node->next;
            node->next = nullptr;
            nextNode->prev = node->prev;
            node->prev = nullptr;
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        return node->val;
    }
    
    void put(int key, int value) {
        ListNode* temp;
        if(mp.find(key) == mp.end()) {
            if(cnt == 0) {
                ListNode* temp = head;
                head = head->next;
                temp->next = nullptr;
                mp.erase(head->key);
            }
            temp = new ListNode(key, value);
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
            if(cnt > 0)
                cnt--;
        }
        else {
            temp = mp[key];
            temp->val = value;
            if(tail == temp)
                return;
            ListNode* prevNode = temp->prev;
            ListNode* nextNode = temp->next;
            prevNode->next = temp->next;
            temp->next = nullptr;
            nextNode->prev = temp->prev;
            temp->prev = nullptr;
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
        mp[key] = temp;
    }
};
