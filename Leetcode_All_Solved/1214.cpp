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
    bool search(TreeNode* root2, const int& val){
        if(root2==nullptr) return false;

        if(root2->val == val) return true;

        if(val < root2->val)
            return search(root2->left, val);
        else return search(root2->right, val);
    }
    bool preorder(TreeNode* root1, TreeNode* root2, const int& target){
        if(root1==nullptr) return false;

        if( search(root2, target - root1->val) ) return true;
        return
            preorder(root1->left, root2, target) ||
            preorder(root1->right, root2, target);

    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return preorder(root1, root2, target);
    }
};
