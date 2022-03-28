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
    void sum_descendants(TreeNode* root, int depth, int& sum){
        if(root == nullptr)return;
        if(depth == 0){
            sum += root->val;
            return;
        }
        sum_descendants(root->left, depth-1, sum);
        sum_descendants(root->right, depth-1, sum);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root == nullptr)return 0;
        int ans = sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        if(root->val %2 == 0){
            sum_descendants(root, 2, ans);
        }
        return ans;
    }
};
