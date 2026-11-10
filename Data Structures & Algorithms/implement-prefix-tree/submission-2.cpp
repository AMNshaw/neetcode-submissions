class PrefixTree {
public:
    struct TrieNode{
        TrieNode() = default;
        bool word = false;
        std::unordered_map<char, TrieNode*> children;
    };

    PrefixTree() {
        root_ = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root_;
        for(const char& c : word){
            if(!node->children.count(c)){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = true;
    }
    
    bool search(string word) {
        TrieNode* node = root_;
        for(const auto& c : word){
            if(!node->children.count(c))
                return false;
            
            node = node->children[c];
        }
        return node->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root_;
        for(const auto& c : prefix){
            if(!node->children.count(c))
                return false;
            
            node = node->children[c];
        }
        return true;
    }

private:
    TrieNode* root_;

};
