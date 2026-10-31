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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(isSameTree(root, subRoot)){
            return true;
        }
              
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return true;

        if(!t1 || !t2 || t1->val != t2->val) return false;

        bool same_l = isSameTree(t1->left, t2->left);
        bool same_r = isSameTree(t1->right, t2->right);

        return (t1->val == t2->val && same_l && same_r);
    }
};
