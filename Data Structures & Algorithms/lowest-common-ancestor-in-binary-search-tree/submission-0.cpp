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
        queue<TreeNode*> path_p, path_q;

        BS(root, p->val, path_p);
        BS(root, q->val, path_q);

        TreeNode* same;
        while(!path_p.empty() && !path_q.empty()){
            if(path_p.front()->val == path_q.front()->val){
                same = path_p.front();
                path_p.pop();
                path_q.pop();
            }
                
            else
                break;
        }
        return same;

    }
    void BS(TreeNode* node, int target, queue<TreeNode*>& path){
        if(!node) return;

        path.push(node);
        if(target > node->val)
            BS(node->right, target, path);
        else if(target < node->val)
            BS(node->left, target, path);
        else
            return;
    }
};
