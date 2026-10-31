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
    int max_n = 0;
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int n = 1;
        dfs(root, n);
        return max_n;
    }

    void dfs(TreeNode* node, int n){
        if(!node) return;

        dfs(node->left, n + 1);
        
        dfs(node->right, n + 1);
        
        max_n = max(n, max_n);
    }
};
