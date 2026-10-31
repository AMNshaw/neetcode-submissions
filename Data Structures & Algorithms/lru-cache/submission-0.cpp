class Node{
public:
    int key_;
    int val_;
    Node* prev_;
    Node* next_;

    Node(int k, int v) : key_(k), val_(v), prev_(nullptr), next_(nullptr){}
};

class LRUCache {
public:
    int capacity_;
    unordered_map<int, Node*> mp_;

    Node* dummy_L;
    Node* dummy_R;

    void remove(Node* node){
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
    }

    void insert(Node* node){
        node->prev_ = dummy_R->prev_;
        dummy_R->prev_->next_ = node;
        node->next_ = dummy_R;
        dummy_R->prev_ = node;
    }

    LRUCache(int capacity) {
        capacity_ = capacity;
        mp_.clear();
        dummy_L = new Node(0, 0);
        dummy_R = new Node(0, 0);
        dummy_L->next_ = dummy_R;
        dummy_R->prev_ = dummy_L;
    }
    
    int get(int key) {
        if(mp_.find(key) == mp_.end()) return -1;

        Node *node = mp_[key];
        remove(node);
        insert(node);
        
        return node->val_;
    }
    
    void put(int key, int value) {
        if(mp_.find(key) != mp_.end())
            remove(mp_[key]);
        
        Node* node = new Node(key, value);
        mp_[key] = node;
        insert(node);

        if(mp_.size() > capacity_){
            Node* LRU = dummy_L->next_;
            remove(LRU);
            mp_.erase(LRU->key_);
            delete LRU;
        }
    }
};
