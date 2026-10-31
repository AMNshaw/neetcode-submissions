struct Node{
    Node(int v) : val(v){}
    int val;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class Deque {
public:
    Deque() {
        head_ = new Node(-1);
        tail_ = new Node(-1);
        head_->next = tail_;
        tail_->prev = head_;
    }

    bool isEmpty() {
        return head_->next == tail_;
    }

    void append(int value) {
        Node* new_node = new Node(value);
        Node* last_node = tail_->prev;

        new_node->next = tail_;
        new_node->prev = last_node;
        last_node->next = new_node;
        tail_->prev = new_node;
    }

    void appendleft(int value) {
        Node* new_node = new Node(value);
        Node* first_node = head_->next;

        new_node->prev = head_;
        new_node->next = first_node;
        first_node->prev = new_node;
        head_->next = new_node;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* last_node = tail_->prev;
        last_node->prev->next = tail_;
        tail_->prev = last_node->prev;
        int val = last_node->val;
        delete last_node;
        return val;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Node* first_node = head_->next;

        first_node->next->prev = head_;
        head_->next = first_node->next;
        int val = first_node->val;
        delete first_node;
        return val;
    }

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};
