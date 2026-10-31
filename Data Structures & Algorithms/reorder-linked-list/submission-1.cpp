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
        if(!head || !head->next) return;

        auto single_sh = head;
        auto double_sh = head;
        while(double_sh -> next && double_sh->next->next){
            single_sh = single_sh->next;
            double_sh = double_sh->next->next;
        }
        auto right_start = single_sh->next;
        single_sh->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = right_start;
        while(curr){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        right_start = prev;

        ListNode* first = head; 
        ListNode* second = right_start;
        while(second){
            ListNode* f_next = first->next;
            ListNode* s_next = second->next;

            first->next = second;
            second->next = f_next;

            first = f_next;
            second = s_next;
        }
    }
};

