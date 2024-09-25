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
#define tti tuple<TreeNode*, int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int limit;
    tti postorder(TreeNode* node, int pref){
        assert(node);

        //base case
        if(!node->left && !node->right){
            return { (pref + node->val >= limit)? node:nullptr, node->val };
        }

        int max_suf = INT_MIN;
        if(node->left){
            auto [child, suf] = postorder(node->left, pref + node->val);
            node->left = child;
            max_suf = max(max_suf, suf);
        }
        if(node->right){
            auto [child, suf] = postorder(node->right, pref + node->val);
            node->right = child;
            max_suf = max(max_suf, suf);
        }
        assert(max_suf != INT_MIN);

        if(pref + node->val + max_suf >= limit) return {node, max_suf + node->val};
        else return {nullptr, max_suf + node->val};
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        this->limit = limit;

        return get<0>( postorder(root, 0) );
    }
};