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
#include<unordered_set>
class FindElements {
private:
    unordered_set<int> cbt_has;
    void complete_binary_tree_index(TreeNode* root, int cbt_idx=1){
        if(root==nullptr)return;
        
        this->cbt_has.insert(cbt_idx);
        complete_binary_tree_index(root->left, cbt_idx*2);
        complete_binary_tree_index(root->right, cbt_idx*2+1);
    }
public:
    FindElements(TreeNode* root) {
        complete_binary_tree_index(root);
    }
    
    bool find(int target) {
        //NOTE: 1-based complete binary tree indexing better
        return this->cbt_has.find(target + 1) != this->cbt_has.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
