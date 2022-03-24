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
    void inorder(TreeNode *root, TreeNode *&inv1, TreeNode *&inv1_pred, TreeNode *& inv2, TreeNode *& inorder_pred){
        if(root != nullptr){
            inorder(root->left,inv1,inv1_pred,inv2,inorder_pred);
            //record inversion
            if(inorder_pred != nullptr && inorder_pred->val > root->val){
                if(inv1 == nullptr){
                    inv1 = root;
                    inv1_pred = inorder_pred;
                }else inv2 = root;
            }
            
            //visit
            inorder_pred = root;
            
            inorder(root->right,inv1,inv1_pred,inv2,inorder_pred);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *inv1 = nullptr, *inv1_pred = nullptr;
        TreeNode *inv2 = nullptr;
        TreeNode *inorder_pred = nullptr;
        inorder(root,inv1,inv1_pred,inv2,inorder_pred);
        
        if(inv2 != nullptr){
            //2 inversion
            int val_tmp = inv1_pred->val;
            inv1_pred->val = inv2->val;
            inv2->val = val_tmp;
        }else{
            //1 inversion
            int val_tmp = inv1_pred->val;
            inv1_pred->val = inv1->val;
            inv1->val = val_tmp;
        }
    }
};
