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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        return dfs(root, p, q);
    }

    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node) return nullptr;

        if(p->val > node->val && q->val > node->val){
           return dfs(node->right, p, q);
        }else if(p->val < node->val && q->val < node->val){
           return dfs(node->left, p, q);
        }

        return node;
    }

};
