struct Trie{
public:
    struct Node{
        Node(){}
        std::unordered_map<char, Node*> children;
        std::string word = "";
    };
    Node* root; 

    Trie(){ root = new Node();}

    void insert(std::string word){
        Node* node = root;
        for(const auto& c : word){
            if(!node->children.count(c)){
                node->children[c] = new Node();
            }
            node = node->children[c];
        }
        node->word = word;
    }

    Node* find(Node* curr, char c){
        if(!curr->children.count(c)) return nullptr;
        return curr->children[c];
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(const auto& word : words){
            trie_.insert(word);
        }

        m_ = board.size();
        n_ = board[0].size();

        for(int i = 0; i < m_; i++){
            for(int j = 0; j < n_; j++){
                dfs(board, i, j, trie_.root, "");
            }
        }        

        return res_;
    }

    void dfs(std::vector<std::vector<char>>& board, int row, int col, Trie::Node* prev_node, std::string prev_word){
        char c = board[row][col];
        if(c == '#') return;
        Trie::Node* curr_node = trie_.find(prev_node, c);
        if(!curr_node) return;
        if(!curr_node->word.empty()){
            res_.push_back(curr_node->word);
            curr_node->word = "";
        }

        char temp = board[row][col];
        board[row][col] = '#';

        for(const auto& dir : dirs_){
            int next_r = row + dir[0];
            int next_c = col + dir[1];
            if(next_r >= m_ || next_r < 0
            || next_c >= n_ || next_c < 0) continue;

            dfs(board, next_r, next_c, curr_node, prev_word + c);
        }

        board[row][col] = temp;
    }

private:
    std::vector<std::string> res_;
    Trie trie_;
    int m_ = 0;
    int n_ = 0;
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
