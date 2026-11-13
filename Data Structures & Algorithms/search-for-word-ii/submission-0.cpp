struct Trie{
public:
    struct Node{
        Node(){}
        std::unordered_map<char, Node*> children;
        bool word = false;
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
        node->word = true;
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
                dfs(board, {i, j}, trie_.root, "");
            }
        }        

        return res_;
    }

    void dfs(std::vector<std::vector<char>>& board, std::vector<int> curr_idx, Trie::Node* prev_node, std::string prev_word){
        char c = board[curr_idx[0]][curr_idx[1]];
        Trie::Node* curr_node = trie_.find(prev_node, c);
        if(!curr_node) return;
        std::string curr_word = prev_word + c;
        if(curr_node->word){
            res_.push_back(curr_word);
            curr_node->word = false;
        }

        char temp = board[curr_idx[0]][curr_idx[1]];
        board[curr_idx[0]][curr_idx[1]] = '#';

        for(const auto& dir : dirs_){
            int next_r = curr_idx[0] + dir[0];
            int next_c = curr_idx[1] + dir[1];
            if(next_r >= m_ || next_r < 0
            || next_c >= n_ || next_c < 0) continue;

            dfs(board, {next_r, next_c}, curr_node, curr_word);
        }

        board[curr_idx[0]][curr_idx[1]] = temp;
    }

private:
    std::vector<std::string> res_;
    Trie trie_;
    int m_ = 0;
    int n_ = 0;
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
