
class Solution {
public:
        
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> random_map;

        Node* curr = head;
        Node* cpy_node = new Node(head->val);
        Node* res = cpy_node;

        random_map[head] = cpy_node;

        while(curr){
            if(curr->random != nullptr){
                if(!random_map.count(curr->random)){
                    random_map[curr->random] = new Node(curr->random->val);
                }
                cpy_node->random = random_map[curr->random];
            }
            curr = curr->next;
            if(curr != nullptr){
                if(!random_map.count(curr)){
                    cpy_node->next = new Node(curr->val);
                    random_map[curr] = cpy_node->next;
                }else{
                    cpy_node->next = random_map[curr];
                }
                cpy_node = cpy_node->next;
            }
        }

        return res;
    }
};
