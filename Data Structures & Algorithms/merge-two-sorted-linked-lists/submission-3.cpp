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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *lil, *big;

        if(list1->val < list2->val){
            lil = list1;
            big = list2;
        }
        else{
            lil = list2;
            big = list1;
        }

        lil->next = mergeTwoLists(lil->next, big);

        return lil;
    }
};
