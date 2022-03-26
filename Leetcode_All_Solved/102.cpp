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
#include<unordered_map>
#include<utility>
#include<queue>
class Solution {
private:
    void preorder(TreeNode* root, unordered_map<TreeNode*,int>& level_m, int level=0){
        if(root == nullptr)return;
        
        pair<TreeNode*,int> p (root, level);
        level_m.insert(p);
        
        preorder(root->left, level_m, level+1);
        preorder(root->right, level_m, level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //get levels
        unordered_map<TreeNode*,int> level_m;
        preorder(root, level_m);
        
        //level order traversal
        vector<vector<int>> ans;
        vector<int> ans1level;
        queue<TreeNode*> q;
        if(root == nullptr)return ans;
        q.push(root);
        
        int cur_level = 0;
        while(q.size() != 0){
            TreeNode* n = q.front();
            q.pop();
            if(level_m.find(n)->second == cur_level+1){
                ans.push_back(ans1level);
                ans1level.clear();
                cur_level++;
            }
            
            ans1level.push_back(n->val);
            
            if(n->left != nullptr)q.push(n->left);
            if(n->right != nullptr)q.push(n->right);
        }
        ans.push_back(ans1level);
        
        return ans;
    }
};
