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
#include<stack>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //NOTE: variant level order traversal, with current level info
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        int cur_level = 0;
        while(q.size() != 0){
            int level_size = q.size();
            vector<int> ans1level;
            
            stack<TreeNode*> s;
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                if(cur_level %2 == 0)
                    ans1level.push_back(n->val);
                else s.push(n);
                
                if(n->left != nullptr)q.push(n->left);
                if(n->right != nullptr)q.push(n->right);
            }
            
            if(cur_level %2 ==1){
                while(s.size() != 0){
                    TreeNode* n = s.top();
                    s.pop();
                    ans1level.push_back(n->val);
                }
            }
            
            cur_level++;
            ans.push_back(ans1level);
        }
        return ans;
    }
};
