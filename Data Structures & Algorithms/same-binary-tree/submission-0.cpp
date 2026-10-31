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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        queue<TreeNode*> pq;
        queue<TreeNode*> qq; 
        pq.push(p);
        qq.push(q);
        while(!pq.empty() && !qq.empty()){
            TreeNode* node_p = pq.front();
            TreeNode* node_q = qq.front();
            pq.pop();
            qq.pop();
            if(node_p){
                if(!node_q || node_p->val != node_q->val){
                    return false;
                }
                pq.push(node_p->left);
                pq.push(node_p->right);
            }
            if(node_q){
                if(!node_p)
                    return false;
                qq.push(node_q->left);
                qq.push(node_q->right);
            }
        }
        if(!pq.empty() || !qq.empty()) return false;
        return true;
    }
};

