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
    int minDepth(TreeNode* root) {
        //NOTE: variant level order traversal, with current level info
        queue<TreeNode*> q;
        if(root==nullptr)return 0;
        q.push(root);
        
        int cur_level = 1;
        while(q.size() != 0){
            int level_size = q.size();
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                
                if(n->left == nullptr && n->right == nullptr)return cur_level;
                
                if(n->left != nullptr)q.push(n->left);
                if(n->right != nullptr)q.push(n->right);
            }
            
            cur_level++;
        }
        return (-1);//not here
    }
};
