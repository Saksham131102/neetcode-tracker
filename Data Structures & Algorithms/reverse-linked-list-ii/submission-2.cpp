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
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i=0;i<left-1;i++) {
            prev = prev->next;
        }

        ListNode* sublistHead = prev->next;
        ListNode* sublistTail = sublistHead;
        
        for(int i=0;i<right - left;i++) {
            sublistTail = sublistTail->next;
        }

        ListNode* nextNode = sublistTail->next;
        sublistTail->next = nullptr;
        prev->next = reverseLL(sublistHead);
        sublistHead->next = nextNode;

        return dummy->next;
    }
};