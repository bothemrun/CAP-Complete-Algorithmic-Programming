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
        
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        //ok for low==high
        root->left = divide_conquer(nums, low, mid-1);
        root->right = divide_conquer(nums, mid+1, high);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return divide_conquer(nums, 0, nums.size()-1);
    }
};