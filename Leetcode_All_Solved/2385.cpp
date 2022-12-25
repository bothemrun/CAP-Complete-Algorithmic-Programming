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
 #include<unordered_map>
 #include<algorithm>
class Solution {
public:
    unordered_map<TreeNode*, int> start_path2d;

    bool find_node(TreeNode* root, const int& start, int& d2start){
        if(root == nullptr)return false;

        if(root->val == start){
            d2start = 1;

            start_path2d[root] = 0;
            return true;
        }

        int d2start_l, d2start_r;
        bool l = find_node(root->left, start, d2start_l);
        bool r = false;
        if(l == false)
            r = find_node(root->right, start, d2start_r);
        
        if(l) d2start = d2start_l + 1;
        else if(r) d2start = d2start_r + 1;

        if(l || r) start_path2d[root] = d2start - 1;

        return l || r;
    }

    int max_depth(TreeNode* root, const int& depth=0){
        if(root == nullptr)return (-1); //NOTE: 0;

        //NOTE: not along sart path
        int this_depth = (-1); //NOTE: 0;
        if(start_path2d.count(root->left) == 0)
            this_depth = max(
                this_depth, 
                max_depth(root->left, depth+1) 
            );

        if(start_path2d.count(root->right) == 0)
            this_depth = max(
                this_depth, 
                max_depth(root->right, depth+1) 
            );
        
        return this_depth + 1;
    }

    int amountOfTime(TreeNode* root, int start) {
        int d2start;
        find_node(root, start, d2start);


        int max_time = 0;
        for(unordered_map<TreeNode*, int>::iterator it = start_path2d.begin();it != start_path2d.end();it++){
            max_time = max(
                max_time,
                max_depth(it->first) + it->second
            );
        }
        return max_time;
    }
};
