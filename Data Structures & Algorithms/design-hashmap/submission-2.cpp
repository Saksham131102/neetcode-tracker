class MyHashMap {
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
        }
    };

    vector<ListNode*> map;
    int hash(int key) {
        return key % map.size();
    }
public:
    MyHashMap() {
        map.resize(10000);
        for(auto &bucket : map) {
            bucket = new ListNode(0, 0);
        }
    }
    
    void put(int key, int value) {
        ListNode *curr = map[hash(key)];
        while(curr->next) {
            if(curr->next->key == key) {
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key, value);
    }
    
    int get(int key) {
        ListNode* curr = map[hash(key)];
        while(curr->next) {
            if(curr->next->key == key) {
                return curr->next->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode *curr = map[hash(key)];
        while(curr->next) {
            if(curr->next->key == key) {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */