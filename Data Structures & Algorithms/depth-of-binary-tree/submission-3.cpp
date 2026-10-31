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
        
        return dfs(root);
    }

    int dfs(TreeNode* node){
        if(!node) return 0;
        int ld = dfs(node->left);
        int rd = dfs(node->right);
        return max(ld, rd) + 1;
    }
};
