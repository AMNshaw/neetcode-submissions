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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> nestList;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> currLayer;
            int levelSize = q.size();
            
            for(int i=0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);

                currLayer.push_back(node->val);
                
            }
            nestList.push_back(currLayer);
        }

        return nestList;
    }
};
