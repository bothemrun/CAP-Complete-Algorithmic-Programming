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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ave;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0){
            int level_size = q.size();
            double level_sum = 0;
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                level_sum += n->val;
                
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            ave.push_back( level_sum / level_size );
        }
        return ave;
    }
};
