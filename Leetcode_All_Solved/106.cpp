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
    int cur_post_root;//NOTE: not 0
    unordered_map<int,int> in_val2idx;
    inline void init(const vector<int>& inorder){
        this->cur_post_root = inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            pair<int,int> p(inorder[i],i);
            this->in_val2idx.insert(p);
        }
    }
    TreeNode* tree(const vector<int>& inorder, const vector<int>& postorder, int in_low, int in_high){
        if(in_low > in_high)return nullptr;
        
        int cur_in_root = this->in_val2idx.find(postorder[(this->cur_post_root)--])->second;
        TreeNode* root = new TreeNode(inorder[cur_in_root]);
        //NOTE: must build right subtree first, for cur_post_root
        root->right = tree(inorder, postorder, cur_in_root + 1, in_high);
        root->left = tree(inorder, postorder, in_low, cur_in_root - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        init(inorder);
        return tree(inorder, postorder, 0, inorder.size()-1);
    }
};
