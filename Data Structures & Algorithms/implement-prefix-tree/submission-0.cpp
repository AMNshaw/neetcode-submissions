class TrieNode {
public:
    unordered_map<char, TrieNode*> children_;
    bool isEndOfWord_ = false;
};

class PrefixTree {
public:
    TrieNode* root_;

    PrefixTree() {
        root_ = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root_;

        for(auto& c : word){
            if(!curr->children_.count(c)){
                curr->children_[c] = new TrieNode();
            }
            curr = curr->children_[c];
        }
        curr->isEndOfWord_ = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root_;

        for(auto& c : word){
            if(!curr->children_.count(c)){
                return false;
            }
            curr = curr->children_[c];
        }
        return curr->isEndOfWord_;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root_;

        for(auto& c : prefix){
            if(!curr->children_.count(c)){
                return false;
            }
            curr = curr->children_[c];
        }
        return true;
    }
};
