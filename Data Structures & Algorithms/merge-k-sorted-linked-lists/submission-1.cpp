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

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        auto compare = [](ListNode* a, ListNode* b) { 
            return a->val > b->val; 
        };
        priority_queue<ListNode*, 
                        vector<ListNode*>, 
                        decltype(compare)> pq(compare);

        for(auto &list : lists)
            if(list) pq.push(list);

        ListNode *currMinNode;
        while(!pq.empty()){
            currMinNode = pq.top();
            pq.pop();
            
            curr->next = currMinNode;
            curr = curr->next;

            if(currMinNode->next)
                pq.push(currMinNode->next);
        }        
               
        return dummy->next;
    }
};
