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
        
        auto cmp = [](ListNode* a, ListNode* b){ return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);

        for(auto &list : lists)
            heap.push(list);

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!heap.empty()){
            auto mini = heap.top();
            heap.pop();

            curr->next = mini;
            curr = curr->next;

            if(mini->next)
                heap.push(mini->next);

        }
        return dummy->next;
    }
};
