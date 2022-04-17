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
class Solution {
private:
    TreeNode* divide_conquer(const vector<int>& pre, const vector<int>& post, int pre_low, int pre_high, int post_low, int post_high){
        if(pre_low > pre_high)return nullptr;
        TreeNode* root = new TreeNode( pre.at(pre_low) );
        pre_low++; post_high--;
        if(pre_low > pre_high)return root;
        
        int offset;
        unordered_set<int> left_subtree;
        for(int i=0;i<(pre_high-pre_low+1);i++){
            int pre_val = pre.at(pre_low+i);
            int post_val = post.at(post_low+i);
            if(left_subtree.count(pre_val) == 0)
                left_subtree.insert(pre_val);
            else left_subtree.erase(pre_val);
            
            if(left_subtree.count(post_val) == 0)
                left_subtree.insert(post_val);
            else left_subtree.erase(post_val);
            
            if(left_subtree.size() == 0){
                offset = i;
                break;
            }
        }
        
        root->left = divide_conquer(pre, post, pre_low, pre_low+offset, post_low, post_low+offset);
        root->right = divide_conquer(pre, post, pre_low+offset+1, pre_high, post_low+offset+1, post_high);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return divide_conquer(preorder, postorder, 0, preorder.size()-1, 0, postorder.size()-1);
    }
};
