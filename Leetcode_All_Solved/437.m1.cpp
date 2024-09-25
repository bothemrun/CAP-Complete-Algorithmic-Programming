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
//O(n)
class Solution {
public:
    int ans = 0;
    unordered_map<long long, int> sum2cnt;
    long long targetSum;
    
    void backtrack(TreeNode* node, long long last_prefix){
        if(node == nullptr) return;
        
        long long cur_prefix = last_prefix + node->val;
        ans += sum2cnt[ cur_prefix - targetSum ];
        
        sum2cnt[cur_prefix]++;
        backtrack(node->left, cur_prefix);
        backtrack(node->right, cur_prefix);
        sum2cnt[cur_prefix]--;//backtracking
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        //crucial for prefix sum
        sum2cnt[0] = 1;
    
        this->targetSum = targetSum;
        backtrack(root, 0);
        return ans;
    }
};