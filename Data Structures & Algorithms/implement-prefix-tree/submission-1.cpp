class PrefixTree {
public:
    struct PrefixNode{
        std::unordered_map<char, PrefixNode*> children;
        bool is_word_end = false;

        PrefixNode(){};
    };

    PrefixNode* root_;

    PrefixTree() {
        root_ = new PrefixNode();
    }   
    
    void insert(string word) {
        PrefixNode* curr = root_; 

        for(const char& c : word){
            if(!curr->children.count(c)){
                curr->children[c] = new PrefixNode();    
            }
            curr = curr->children[c];
        }
        curr->is_word_end = true;
    }
    
    bool search(string word) {
        PrefixNode* curr = root_;

        for(const char& c : word){
            if(!curr->children.count(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return curr->is_word_end;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* curr = root_;

        for(const char& c : prefix){
            if(!curr->children.count(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
