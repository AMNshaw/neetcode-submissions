struct Node{
    Node(int k, int v) : key(k), val(v), next(nullptr) {}
    int key;
    int val;
    Node* next;
};

class HashTable {
public:
    HashTable(int capacity) {
        capacity_ = capacity;
        size_ = 0;

        table_.assign(capacity, nullptr);
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        if(!table_[index]){
            table_[index] = new Node(key, value);
        }else{
            Node* prev = nullptr;
            Node* curr = table_[index];
            while(curr){
                if(curr->key == key){
                    curr->val = value;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            prev->next = new Node(key, value);
        }
        size_ ++;

        if(size_ * 2 >= capacity_){
            resize();
        }
    }

    int get(int key) {
        int index = hashFunction(key);

        Node* node = table_[index];
        while(node){
            if(node->key == key) return node->val;
            node = node->next;
        }
        
        return -1;
    }

    bool remove(int key) {
        int index = hashFunction(key);
        if(!table_[index])
            return false;
        
        Node* prev = nullptr;
        Node* curr = table_[index];
        while(curr){
            if(curr->key == key){
                if (prev) prev->next = curr->next;
                else table_[index] = curr->next;
                delete curr;
                size_--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    int getSize() const {
        return size_;
    }

    int getCapacity() const {
        return capacity_;
    }

    void resize() {
        int old_capacity = capacity_;
        capacity_ *= 2;
        vector<Node*> new_table(capacity_, nullptr);

        for(int i=0; i < old_capacity; ++i){
            Node* curr = table_[i];
            Node* new_node = new_table[i];
            while(curr){
                int new_idx = hashFunction(curr->key);
                if(!new_table[new_idx]){
                    new_table[new_idx] = curr;
                }else{
                    Node* new_curr = new_table[new_idx];
                    while(new_curr->next){
                        new_curr = new_curr->next;
                    }
                    new_curr->next = curr;
                }
                curr = curr->next;
            }
        }
        table_ = std::move(new_table);
    }

private:
    int hashFunction(int key){
        return key % capacity_;
    }

    int capacity_;
    int size_;
    std::vector<Node*> table_;

};
