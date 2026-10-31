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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> nodeSet;

        ListNode* node = head;

        while(node){
            if(!nodeSet.count(node))
                nodeSet.insert(node);
            else
                return true;
            
            node = node->next;
        }
        return false;
    }
};
