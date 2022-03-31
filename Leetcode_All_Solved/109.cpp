/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> nums;
    TreeNode* divide_conquer(int low, int high){
        if(low > high)return nullptr;//NOTE: made ok for low==high
        
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        //ok for low==high
        root->left = divide_conquer(low, mid-1);
        root->right = divide_conquer(mid+1, high);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        for(;head != nullptr;head = head->next)nums.push_back(head->val);
        
        return divide_conquer(0, nums.size()-1);
    }
};
