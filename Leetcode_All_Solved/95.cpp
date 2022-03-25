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
    //NOTE: struct, class : pass/return by value (copy)
    vector<TreeNode*> dfs_return_vec_by_copy(const int& from, const int& to){
        vector<TreeNode*> ans;//NOTE: return by copying
        
        if(from == to){
            ans.push_back(new TreeNode(from));//NOTE: new struct()
            return ans;
        }
        if(from > to){
            ans.push_back(nullptr);
            return ans;
        }
        
        for(int root=from;root<=to;root++){
            vector<TreeNode*> l_subtree_v = dfs_return_vec_by_copy(from, root-1);
            vector<TreeNode*> r_subtree_v = dfs_return_vec_by_copy(root+1, to);
            
            for(TreeNode* l_subtree:l_subtree_v)
                for(TreeNode* r_subtree:r_subtree_v)
                    ans.push_back(new TreeNode(root, l_subtree, r_subtree));//NOTE: new struct()
        }
        
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs_return_vec_by_copy(1, n);
    }
};
