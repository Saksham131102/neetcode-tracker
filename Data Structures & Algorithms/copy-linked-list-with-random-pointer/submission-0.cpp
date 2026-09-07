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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* dummy = new Node(-1);
        Node* idx = head;
        Node* prev = dummy;
        
        while(idx != nullptr) {
            Node* curr = new Node(idx->val);
            mp[idx] = curr;
            curr->random = idx;
            prev->next = curr;
            prev = curr;
            idx = idx->next;
        }

        idx = dummy->next;
        while(idx != nullptr) {
            idx->random = mp[idx->random->random];
            idx = idx->next;
        }

        return dummy->next;
    }
};
