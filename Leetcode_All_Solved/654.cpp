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
    TreeNode* divide_conquer(const vector<int>& nums, int low, int high){
        if(low > high)return nullptr;
        if(low == high)return new TreeNode(nums.at(low));
        
        int max_idx = low;
        for(int i=low;i<=high;i++)if(nums.at(i) > nums.at(max_idx)) max_idx = i;
        
        return new TreeNode(nums.at(max_idx), divide_conquer(nums, low, max_idx - 1), divide_conquer(nums, max_idx + 1, high) );
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return divide_conquer(nums, 0, nums.size()-1);
    }
};
