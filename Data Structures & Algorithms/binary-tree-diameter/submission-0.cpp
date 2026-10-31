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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxHeight(root);
        return d;
    }

    int maxHeight(TreeNode* node){
        if(!node) return 0;
        auto lh = maxHeight(node->left);
        auto rh = maxHeight(node->right);

        d = max(d, rh + lh);

        return max(lh, rh) + 1;
    }
};
