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
        if(head == nullptr)
            return head;
        
        for(Node* curr = head ; curr != nullptr ; curr = curr->next->next) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
        }

        for(Node* curr = head ; curr != nullptr ; curr = curr->next->next) {
            if(curr->random != nullptr)
                curr->next->random = curr->random->next;
        }

        Node* newNode = head->next;
        for(Node* curr = head ; curr != nullptr ; curr = curr->next) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if(copy->next != nullptr)
                copy->next = copy->next->next;
        }

        return newNode;
    }
};
