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
    int postorder(TreeNode* root, const int& target, vector<int>& path_sum){
        if(root == nullptr)return 0;
        
        vector<int> l_path_sum, r_path_sum;
        int meet_target = 0;
        meet_target += postorder(root->left, target, l_path_sum);
        meet_target += postorder(root->right, target, r_path_sum);
        
        for(int sum:l_path_sum){
            if(sum+root->val == target)meet_target++;
            path_sum.push_back(sum+root->val);//might have 0
        }
        for(int sum:r_path_sum){
            if(sum+root->val == target)meet_target++;
            path_sum.push_back(sum+root->val);//might have 0
        }
        
        if(root->val == target)meet_target++;
        path_sum.push_back(root->val);
        
        return meet_target;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path_sum;
        return postorder(root, targetSum, path_sum);
    }
};
