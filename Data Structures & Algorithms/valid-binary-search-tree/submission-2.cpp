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
    bool isValidBST(TreeNode* root) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        return dfs(root, mini, maxi);
    }

    bool dfs(TreeNode* node, int& mini, int& maxi){
        if(!node) return true;
        if(node->val <= mini || node->val >= maxi) return false;
        return dfs(node->left, mini, node->val) && dfs(node->right, node->val, maxi);
    }
};