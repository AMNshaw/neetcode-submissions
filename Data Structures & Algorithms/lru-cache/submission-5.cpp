class Node{
public:
    int key_;
    int val_;

    Node* next_;
    Node* prev_;

    Node(int k, int v) : key_(k), val_(v), next_(nullptr), prev_(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache_;

    Node *dummy_L_;
    Node *dummy_R_;

    int capacity_;

    void remove(Node* node){
        node->next_->prev_ = node->prev_;
        node->prev_->next_ = node->next_;
    }

    void insert(Node* node){
        dummy_R_->prev_->next_ = node;
        node->next_ = dummy_R_;
        node->prev_ = dummy_R_->prev_;
        dummy_R_->prev_ = node;
    }

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        dummy_L_ = new Node(0, 0);
        dummy_R_ = new Node(0, 0);
        dummy_L_->next_ = dummy_R_;
        dummy_R_->prev_ = dummy_L_;
        cache_.clear();
    }
    
    int get(int key) {
        if(cache_.find(key) == cache_.end()) return -1;

        remove(cache_[key]);
        insert(cache_[key]);

        return cache_[key]->val_;
    }
    
    void put(int key, int value) {
        if(cache_.find(key) != cache_.end())
            remove(cache_[key]);
        else if(cache_.size() == capacity_){
            Node* LRU = dummy_L_->next_;
            remove(LRU);
            cache_.erase(LRU->key_);
            delete LRU;
        }
        Node* newNode = new Node(key, value);
        cache_[key] = newNode;
        insert(newNode);
    }
};
