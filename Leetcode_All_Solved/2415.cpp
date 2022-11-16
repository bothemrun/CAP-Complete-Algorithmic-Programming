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
#include<algorithm>//reverse()
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int level_cnt = 0;
        vector<TreeNode*> parent;
        while(q.size() != 0){
            int level_size = q.size();
            vector<TreeNode*> level;
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                
                level.push_back(n);
                
                if(n->left != nullptr)q.push(n->left);
                if(n->right != nullptr)q.push(n->right);
            }
            
            
            if(level_cnt%2 == 1)
                reverse(level.begin(), level.end());
            for(int i=0;i<parent.size();i++){
                parent[i]->left = level[2*i];
                parent[i]->right = level[2*i+1];
            }
            
            parent.clear();
            parent = level;
            
            level_cnt++;
        }
        
        return root;
    }
};
