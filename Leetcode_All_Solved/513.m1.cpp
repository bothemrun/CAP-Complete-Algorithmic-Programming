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
class Solution {
private:
    int max_level = 0;
    int leftmost_lastly_updated_val;//of last row
    void flipped_preorder_level(TreeNode* root, int level=0){
        if(root == nullptr)return;
        if(level == max_level+1)max_level++;
        if(level == max_level)this->leftmost_lastly_updated_val = root->val;//the above case will come too
        
        //NOTE: must left last
        flipped_preorder_level(root->right, level+1);
        flipped_preorder_level(root->left, level+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        flipped_preorder_level(root);
        return this->leftmost_lastly_updated_val;
    }
};
