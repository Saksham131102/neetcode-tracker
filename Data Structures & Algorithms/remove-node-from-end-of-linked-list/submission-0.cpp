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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        int size = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            size++;
            temp = temp->next;
        }
        int pos = size - n - 1;
        if(pos < 0)
            return head->next;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(pos--) {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = nullptr;
        return head;
    }
};
