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
#include<queue>
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0){
            int level_size = q.size();
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                
                if(n == u){
                    if(i == level_size-1)return nullptr;
                    else return q.front();
                }
                
                if(n->left != nullptr)q.push(n->left);
                if(n->right != nullptr)q.push(n->right);
            }
        }
        
        return nullptr;
    }
};
