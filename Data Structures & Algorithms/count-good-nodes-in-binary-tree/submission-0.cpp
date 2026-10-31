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
    int res = 0;

    int goodNodes(TreeNode* root) {
        
        dfs(root, root->val);
        return res;
    }

    void dfs(TreeNode* node, int curr_max){
        if(!node) return;

        if(node->val >= curr_max) {
            res++;
            curr_max = node->val;
        }
            
        dfs(node->left, curr_max);
        dfs(node->right, curr_max);
    }
};
