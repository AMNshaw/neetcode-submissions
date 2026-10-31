/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val.
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == nullptr || (head->next == nullptr && n > 0)) return nullptr;

        ListNode* ahead = head;
        ListNode* curr = head;

        for(int i=0; i < n; ++i){
            ahead = ahead->next;
        }

        if(ahead == nullptr) return head->next;

        while(ahead->next != nullptr){
            curr = curr->next;
            ahead = ahead->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};