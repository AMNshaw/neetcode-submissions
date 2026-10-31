/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        queue<TreeNode*> q_nodes;
        q_nodes.push(p);
        q_nodes.push(q);
        
        while(!q_nodes.empty()){
            TreeNode* currP = q_nodes.front(); q_nodes.pop();
            TreeNode* currQ = q_nodes.front(); q_nodes.pop();

            if(!currP && !currQ) continue;

            if(!currP || !currQ || currP->val != currQ->val) return false;

            q_nodes.push(currP->left);
            q_nodes.push(currQ->left);
            q_nodes.push(currP->right);
            q_nodes.push(currQ->right);
        }

        return true;
    }
};
