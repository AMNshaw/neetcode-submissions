class TrieNode{
public:
    unordered_map<char, TrieNode*> children_;
    bool isEndOfWord_ = false;
};

class WordDictionary {
public:
    WordDictionary() {
        root_ = new TrieNode();
    }
    
    void addWord(string word) {
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
        queue<pair<TrieNode*, int>> q;
        q.push({root_, 0});

        while (!q.empty()) {
            auto [node, idx] = q.front();
            q.pop();

            if (idx == word.length()) {
                if (node->isEndOfWord_) return true;
                continue;
            }

            char ch = word[idx];
            if (ch == '.') {
                for (auto& [c, child] : node->children_) {
                    q.push({child, idx + 1});
                }
            } else {
                if (node->children_.count(ch)) {
                    q.push({node->children_[ch], idx + 1});
                }
            }
        }

        return false;
    }

    TrieNode* root_;
};
