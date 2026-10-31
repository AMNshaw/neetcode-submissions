/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        return (node) ? bfs(node) : nullptr;
    }

    Node* bfs(Node* node){
        unordered_map<Node*, Node*> cloneMap;
        queue<Node*> q;
        Node* cloneNode = new Node(node->val);

        cloneMap[node] = cloneNode;
        q.push(node);

        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();

            for(auto &nei : currNode->neighbors){
                if(cloneMap.find(nei) == cloneMap.end()){
                    q.push(nei);
                    Node* nd = new Node(nei->val);
                    cloneMap[nei] = nd;
                }

                cloneMap[currNode]->neighbors.push_back(cloneMap[nei]);
            }
            
        }
        return cloneNode;
    }
};
