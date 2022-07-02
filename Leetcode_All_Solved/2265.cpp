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
    int ans = 0;
    void postorder(TreeNode* root, int &cnt, int &sum){
        if(root == nullptr)return;//cnt sum already init=0
        
        int cnt_left = 0, cnt_right = 0;
        int sum_left = 0, sum_right = 0;
        postorder(root->left, cnt_left, sum_left);
        postorder(root->right, cnt_right, sum_right);
        cnt = 1 + cnt_left + cnt_right;
        sum = root->val + sum_left + sum_right;
        if(root->val == sum / cnt)ans++;
        return;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0, sum = 0;
        postorder(root, cnt, sum);
        return ans;
    }
};
