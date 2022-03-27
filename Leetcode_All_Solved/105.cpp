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
class Solution {
private:
    int cur_pre_root;
    unordered_map<int,int> in_val2idx;
    inline void init(const vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            pair<int,int> p(inorder[i],i);
            this->in_val2idx.insert(p);
        }
    }
    TreeNode* tree(const vector<int>& preorder, const vector<int>& inorder, int in_low, int in_high){
        if(in_low > in_high)return nullptr;
        
        int cur_in_root = this->in_val2idx.find(preorder[this->cur_pre_root])->second;
        TreeNode* root = new TreeNode(preorder[(this->cur_pre_root)++]);
        //NOTE: must build left subtree first
        root->left = tree(preorder, inorder, in_low, cur_in_root - 1);
        root->right = tree(preorder, inorder, cur_in_root + 1, in_high);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        init(inorder);
        return tree(preorder, inorder, 0, inorder.size()-1);
    }
};
