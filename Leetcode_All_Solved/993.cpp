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
public:
    int depth_x, depth_y;
    TreeNode *parent_x, *parent_y;
    bool anyorder(TreeNode *root, int depth, const int& x, const int& y, int found, TreeNode *parent){
        if(root == nullptr)return false;
        if(root->val == x){
            depth_x = depth;
            found++;
            parent_x = parent;
        }
        if(root->val == y){
            depth_y = depth;
            found++;
            parent_y = parent;
        }
        if(found == 2)return true;//done
        
        if(anyorder(root->left, depth+1, x, y, found, root))return true;
        if(anyorder(root->right, depth+1, x, y, found, root))return true;
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        anyorder(root, 0, x, y, 0, nullptr);
        return depth_x == depth_y && parent_x != parent_y;
    }
};
