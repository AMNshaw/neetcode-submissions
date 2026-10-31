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
    TreeNode* reversed_tree_;
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        dfs(root);
        return root;        
    }

    void dfs(TreeNode* node){
        if(node == nullptr){
            return;
        }
        dfs(node->left);
        dfs(node->right);
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
