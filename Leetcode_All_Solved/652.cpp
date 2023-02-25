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
#include<unordered_map>
class Solution {
public:
    const string delim = ",";
    const string null = "n";

    unordered_set<string> dup_serial;
    unordered_map<string, TreeNode*> dup_serial2node;
    void preorder_serial(TreeNode* root, string& serial){
        if(root == nullptr){
            serial = null;
            return;
        }

        string serial_l, serial_r;
        preorder_serial(root->left, serial_l);
        preorder_serial(root->right, serial_r);

        serial = to_string(root->val) + delim + serial_l + delim + serial_r;
        if(dup_serial.count(serial) != 0)
            dup_serial2node[serial] = root;
        dup_serial.insert(serial);
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string serial;
        preorder_serial(root, serial);

        vector<TreeNode*> dup;
        for(const auto& [key, val]: dup_serial2node)
            dup.push_back(val);
        return dup;
    }
};
