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
        if (!head || !head->next) return;
        ListNode* single_shift = head;
        ListNode* double_shift = head;
        while(double_shift->next && double_shift->next->next){
            single_shift = single_shift->next;
            double_shift = double_shift->next->next;
        }
        ListNode* right_start = single_shift->next;
        single_shift->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = right_start;
        while(curr){
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        right_start = prev;
        
        ListNode* first = head;
        ListNode* second = right_start;
        while(second){
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            
            first->next = second;
            second->next = t1;
            
            first = t1;
            second = t2;
        }
    }
};

