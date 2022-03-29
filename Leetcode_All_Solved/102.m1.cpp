//m1
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //NOTE: variant level order traversal with current level info
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==nullptr)return ans;
        q.push(root);
        while(q.size() != 0){
            int level_size = q.size();
            vector<int> ans1level;
            for(int i=0;i<level_size;i++){
                TreeNode* n =q.front();
                q.pop();
                
                ans1level.push_back(n->val);
                
                if(n->left != nullptr)q.push(n->left);
                if(n->right != nullptr)q.push(n->right);
            }
            ans.push_back(ans1level);
        }
        
        return ans;
    }
};
