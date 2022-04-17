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
private:
    int preorder_idx = 0;
    bool preorder_flip(TreeNode* root, const vector<int>& preorder, vector<int>& flip){
        if(root == nullptr)return true;
        
        if(root->val != preorder.at(preorder_idx))return false;
        
        int preorder_idx_backtrack = ++preorder_idx;
        vector<int> flip_l, flip_r;
        bool match_l, match_r;
        match_l = preorder_flip(root->left, preorder, flip_l);
        match_r = preorder_flip(root->right, preorder, flip_r);
        if(match_l && match_r){
            flip.insert(flip.end(), flip_l.begin(), flip_l.end());
            flip.insert(flip.end(), flip_r.begin(), flip_r.end());
            return true;
        }else preorder_idx = preorder_idx_backtrack;//NOTE
        
        flip_l.clear();
        flip_r.clear();
        match_l = preorder_flip(root->right, preorder, flip_l);
        match_r = preorder_flip(root->left, preorder, flip_r);
        if(match_l && match_r){
            flip.insert(flip.end(), flip_l.begin(), flip_l.end());
            flip.insert(flip.end(), flip_r.begin(), flip_r.end());
            flip.push_back(root->val);
            return true;
        }else preorder_idx = preorder_idx_backtrack;//NOTE
        
        return false;
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flip;
        if(preorder_flip(root, voyage, flip) == false)return vector<int>({-1});
        return flip;
    }
};
