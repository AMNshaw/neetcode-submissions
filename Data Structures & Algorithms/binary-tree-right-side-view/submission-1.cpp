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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*> q;
        q.push(root); 

        vector<int> sideView;

        while(!q.empty()){
            
            int layerSize = q.size();

            for(int i=0; i< layerSize; i++){
                TreeNode *node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                if(i == layerSize-1) sideView.push_back(node->val);

            }

        }
        return sideView;
    }
};
