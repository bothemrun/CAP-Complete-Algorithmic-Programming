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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*> split({nullptr, nullptr});
        if(root==nullptr) return split;

        if(root->val <= target){
            split[0] = root;

            vector<TreeNode*> right_split = splitBST(root->right, target);

            root->right = right_split[0];

            split[1] = right_split[1];
        }else{
            split[1] = root;

            vector<TreeNode*> left_split = splitBST(root->left, target);

            root->left = left_split[1];

            split[0] = left_split[0];
        }

        return split;
    }
};
