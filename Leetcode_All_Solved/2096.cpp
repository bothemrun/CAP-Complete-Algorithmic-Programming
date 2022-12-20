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
 #include<algorithm>//reverse()
class Solution {
public:
    //NOTE: return: 0: nothing found. 2: found both & lca.
    //NOTE: 1: found startValue. (-1):found destValue
    string start = "";
    string dest = "";
    string path;
    int lca_cnt(TreeNode* root, const int& start_value, const int& dest_value){
        if(root == nullptr)return 0;

        int l = lca_cnt(root->left, start_value, dest_value);
        int r = lca_cnt(root->right, start_value, dest_value);
        //already found
        if(l == 2 || r == 2)return 2;

        //now lca
        int cnt = (l != 0) + (r != 0) + (root->val == start_value) + (root->val == dest_value);
        //startValue != destValue
        if(cnt == 2){
            //this is lca
            
            //NOTE: dest: insert for child
            if(l == (-1)) dest += "L";
            else if(r == (-1)) dest += "R";

            reverse(dest.begin(), dest.end());

            path = start + dest;
            return 2;
        }

        //if found 1 of them (can't be both)
        if(l == 1 || r == 1 || root->val == start_value){
            start += "U";
            return 1;
        }else if(l == (-1) || r == (-1) || root->val == dest_value){
            if(l == (-1)) dest += "L";
            else if(r == (-1)) dest += "R";
            //NOTE: dest: insert for child
            //NOTE: so not for root->val == destValue
            
            return (-1);
        }else return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        lca_cnt(root, startValue, destValue);
        return path;
    }
};
