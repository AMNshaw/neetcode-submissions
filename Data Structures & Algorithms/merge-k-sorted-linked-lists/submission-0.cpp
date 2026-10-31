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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int listEndCnt = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while(listEndCnt != lists.size()){
            int min = INT_MAX;
            int minIdx = -1;
            listEndCnt = 0;
            for(int i=0; i< lists.size(); i++){
                if(lists[i] && lists[i]->val < min){
                    min = lists[i]->val;
                    minIdx = i;
                }
            }
            if(minIdx == -1)
                break; 
            ListNode *minNode = lists[minIdx];
            curr->next = minNode;
            curr = curr->next;
        
            lists[minIdx] = lists[minIdx]->next;
        }        
        return dummy->next;
    }
};
