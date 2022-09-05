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
    vector<int> leaf1, leaf2;
    void anyorder(TreeNode* root, vector<int>& leaf){
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr)leaf.push_back(root->val);
        
        anyorder(root->left, leaf);
        anyorder(root->right, leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        anyorder(root1, leaf1);
        anyorder(root2, leaf2);
        if(leaf1.size() != leaf2.size())return false;
        for(int i=0;i<leaf1.size();i++){
            if(leaf1.at(i) != leaf2.at(i))return false;
        }
        return true;
    }
};
