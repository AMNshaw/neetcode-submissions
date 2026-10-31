struct Node{
    Node(int v) : val(v), next(nullptr){}
    int val;
    Node* next;
};

class LinkedList {
public:
    LinkedList() {
        head_ = new Node(-1);
        tail_ = head_;
    }

    int get(int index) {
        Node* node = head_->next;
        int i = 0;
        while(node){
            if(i == index) return node->val;
            i++;
            node = node->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* new_node = new Node(val);
        Node* old_first = head_->next;
        head_->next = new_node;
        new_node->next = old_first;
        if(old_first == nullptr){
            tail_ = new_node;
        }
    }
    
    void insertTail(int val) {
        tail_->next = new Node(val);
        tail_ = tail_->next;
    }

    bool remove(int index) {
        Node* node = head_;
        int i=0;
        while(node && node->next){
            if(i == index){
                Node* to_be_rm = node->next;
                if (to_be_rm == tail_) {
                    tail_ = node;
                }
                node->next = to_be_rm->next;
                delete to_be_rm;
                return true;
            }
            i++;
            node = node->next;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head_->next;
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};