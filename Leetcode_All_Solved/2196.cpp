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
#include<unordered_set>
#include<assert.h>
#define MAX_ID 100000
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<TreeNode*> id2node (MAX_ID+1, nullptr);
        unordered_set<int> parent_set, child_set;
        for(const vector<int>& v:descriptions){
            int parent_id = v[0], child_id = v[1], isLeft = v[2];
            TreeNode *parent = id2node.at(parent_id), *child = id2node.at(child_id);
            if(parent == nullptr){
                parent = new TreeNode(parent_id);
                id2node.at(parent_id) = parent;
            }
            if(child == nullptr){
                child = new TreeNode(child_id);
                id2node.at(child_id) = child;
            }
            
            if(isLeft) parent->left = child;
            else parent->right = child;
            
            parent_set.insert(parent_id);
            child_set.insert(child_id);
        }
        
        for(unordered_set<int>::iterator it = child_set.begin();it != child_set.end();it++)
            parent_set.erase(*it);
        assert(parent_set.size() == 1);
        return id2node.at( *( parent_set.begin() ) );
    }
};
