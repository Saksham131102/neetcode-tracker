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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        unordered_map<ListNode*, ListNode*> prev;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* tail = nullptr;

        while(temp2 != nullptr) {
            prev[temp2] = temp1;
            temp1 = temp2;
            temp2 = temp2->next;
            if(temp2 == nullptr)
                tail = temp1;
        }

        ListNode* start = head;
        while(start != tail) {
            ListNode* start2 = start->next;
            start->next = tail;
            tail->next = start2;
            if(tail->next == tail)
                break;
            tail = prev[tail];
            start = start2;
        }
        tail->next = nullptr;
    }
};
