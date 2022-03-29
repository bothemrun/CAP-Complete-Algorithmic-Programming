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
class Solution {
private:
    vector<TreeNode*> forest;
    unordered_set<int> del_set;
    void vec2set(const vector<int>& to_delete){
        for(int x:to_delete)this->del_set.insert(x);
    }
    TreeNode* forest_delete(TreeNode* root){
        if(root == nullptr)return nullptr;
        root->left = forest_delete(root->left);
        root->right = forest_delete(root->right);
        if(this->del_set.find(root->val) != this->del_set.end()){
            if(root->left != nullptr)this->forest.push_back(root->left);
            if(root->right != nullptr)this->forest.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vec2set(to_delete);
        root = forest_delete(root);
        
        if(root != nullptr)this->forest.push_back(root);
        
        return this->forest;
    }
};
