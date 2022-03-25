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
class Solution {
private:
    //NOTE: struct, class : pass/return by value (copy)
    vector<TreeNode*>& dfs_return_by_ref_mem_in_heap(const int& from, const int& to){
        vector<TreeNode*>* ans_in_heap = new vector<TreeNode*>();
        
        if(from == to){
            ans_in_heap->push_back(new TreeNode(from));//NOTE: new strcut() in heap
            return *ans_in_heap;
        }
        if(from > to){
            ans_in_heap->push_back(nullptr);
            return *ans_in_heap;
        }
        
        for(int root=from;root<=to;root++){
            vector<TreeNode*>& l_subtree_v = dfs_return_by_ref_mem_in_heap(from, root-1);
            vector<TreeNode*>& r_subtree_v = dfs_return_by_ref_mem_in_heap(root+1, to);
            
            for(TreeNode*& l_subtree:l_subtree_v)
                for(TreeNode*& r_subtree:r_subtree_v)
                    ans_in_heap->push_back(new TreeNode(root, l_subtree, r_subtree));//NOTE: new struct() in heap
        }
        
        return *ans_in_heap;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs_return_by_ref_mem_in_heap(1, n);
    }
};
