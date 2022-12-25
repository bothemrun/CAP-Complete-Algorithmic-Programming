/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<unordered_map>
class Solution {
public:
    unordered_map<TreeNode*, int> target_path2d;
    vector<int> ans;

    bool target_postorder(TreeNode* root, TreeNode* target, int& d2target){
        if(root == nullptr)return false;
        if(root == target){
            d2target = 1;

            target_path2d[root] = 0;
            return true;
        }

        int d2target_l, d2target_r;
        bool l = target_postorder(root->left, target, d2target_l);
        bool r = target_postorder(root->right, target, d2target_r);
        if(l) d2target = 1 + d2target_l;
        if(r) d2target = 1 + d2target_r;
        
        if( l || r ) target_path2d[root] = d2target - 1;

        return l || r;
    }

    void get_depth_nodes(TreeNode* root, const int& depth, const int& cur_depth=0){
        if(root == nullptr)return;

        if(cur_depth == depth){
            ans.push_back( root->val );
            return;
        }

        //NOTE:
        if(target_path2d.count(root->left) == 0)
            get_depth_nodes(root->left, depth, cur_depth + 1);
        if(target_path2d.count(root->right) == 0)
            get_depth_nodes(root->right, depth, cur_depth + 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int d2target;
        target_postorder(root, target, d2target);

        for(unordered_map<TreeNode*, int>::iterator it = target_path2d.begin();it != target_path2d.end();it++ ){
            get_depth_nodes(it->first, k - it->second );
        }

        return ans;
    }
};
