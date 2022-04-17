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
class Solution {
private:
    unordered_map<int, int> val2inorder_idx;
    inline void init(const vector<int>& inorder){
        for(int i=0;i<inorder.size();i++)
            val2inorder_idx[inorder[i]] = i;
    }
    TreeNode* divide_conquer(const vector<int>& preorder, const vector<int>& inorder, int in_low, int in_high, int& preorder_idx){
        if(in_low > in_high)return nullptr;
        
        int in_root_idx = val2inorder_idx[preorder[preorder_idx++]];
        TreeNode* root = new TreeNode(inorder[in_root_idx]);
        
        root->left = divide_conquer(preorder, inorder, in_low, in_root_idx-1, preorder_idx);
        root->right = divide_conquer(preorder, inorder, in_root_idx+1, in_high, preorder_idx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        init(inorder);
        int preorder_idx = 0;
        return divide_conquer(preorder, inorder, 0, inorder.size()-1, preorder_idx);
    }
};
