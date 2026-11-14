class PrefixTree{
public:
    struct Node{
        std::unordered_map<char, Node*> children;  
        std::string word = "";
    };

    Node* Root(){ return root_;}

    PrefixTree(){ root_ = new Node();}

    void insert(std::string& word){
        Node* node = root_;

        for(auto& c : word){
            if(!node->children.count(c))
                node->children[c] = new Node();

            node = node->children[c];
        }

        node->word = word;
    }

    Node* find(Node* node, char child){
        return node->children.count(child) ? node->children[child] : nullptr;
    }

private:
    Node* root_;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m_ = board.size();
        n_ = board[0].size();
        
        for(string& word : words){
            trie_.insert(word);
        }

        PrefixTree::Node* start = trie_.Root();

        for(int i = 0; i < m_; i++){
            for(int j = 0; j < n_; j++){
                dfs(board, i, j, start);
            }
        }

        return res_;
    }

    void dfs(std::vector<std::vector<char>>& board, int row, int col, PrefixTree::Node* prev_node){
        char c = board[row][col];
        if(c == '#') return;
        PrefixTree::Node* curr_node = trie_.find(prev_node, c);
        if(!curr_node) return;
        if(!curr_node->word.empty()) {
            res_.push_back(curr_node->word);
            curr_node->word = "";
        }

        board[row][col] = '#';
        for(auto& dir : dirs_){
            int next_r = row + dir[0];
            int next_c = col + dir[1];

            if(next_r >= m_ || next_r < 0
            || next_c >= n_ || next_c < 0) continue;

            dfs(board, next_r, next_c, curr_node);
        }
        board[row][col] = c;
    }


private:
    PrefixTree trie_;
    int m_;
    int n_;
    std::vector<std::string> res_;
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};
