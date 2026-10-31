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

    int sol = 0;

    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        dfs(root, n, k);

        return sol;

    }

    void dfs(TreeNode *node, int &k, int target){
        if(!node)
            return;

        dfs(node->left, k, target);
        k++;
        if(k == target){
            sol = node->val;
            return;
        }
        dfs(node->right, k, target);
    }
};
