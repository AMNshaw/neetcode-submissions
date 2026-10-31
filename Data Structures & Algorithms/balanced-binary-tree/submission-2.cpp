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
    bool result = true;
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        dfs(root);
        return result;
    }

    int dfs(TreeNode* node){
        if(!node) return 0;
        
        auto lh = dfs(node->left);
        auto rh = dfs(node->right);

        if(abs(rh - lh) > 1){
            result = false;
        }

        return max(lh, rh) + 1;
    }
};
