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
#include<algorithm>
#include<unordered_map>
class Solution {
private:
    //both deepest level
    //NOTE: route string := "0"/"1" goes left/right. so the smallest after sorting is the leftmost node.
    unordered_map<string, int> route2val;
    vector<string> route;
    int max_level = 0;
    void preorder_keep_last_level(TreeNode* root, int level=0, string cur_route=""){
        if(root == nullptr)return;
        
        if(level > max_level){
            max_level++;
            this->route2val.clear();
            this->route.clear();
        }
        this->route2val[cur_route] = root->val;
        this->route.push_back(cur_route);
        
        preorder_keep_last_level(root->left, level+1, cur_route + "0");
        preorder_keep_last_level(root->right, level+1, cur_route + "1");
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        preorder_keep_last_level(root);
        
        //
        sort(this->route.begin(), this->route.end());
        return this->route2val.find(route.at(0))->second;
    }
};
