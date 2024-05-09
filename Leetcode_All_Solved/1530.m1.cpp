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

//m1
//O(n * d^2) = O(n^3)

class Solution {
public:
    int ans = 0;
    int distance;

    vector<int> postorder(TreeNode* node){
        if(!node) return vector<int>({});

        if(!node->left && !node->right){
            return vector<int>({1});
        }

        vector<int> dl = postorder(node->left);
        vector<int> dr = postorder(node->right);

        for(const int& l: dl)
            for(const int& r: dr)
                if(l+r <= distance) ans++;
        
        vector<int> d(dl.size() + dr.size());
        int d_i = 0;
        for(const int& l: dl)
            d[d_i++] = l+1;
        for(const int& r: dr)
            d[d_i++] = r+1;
        return d;
    }

    int countPairs(TreeNode* root, int distance) {
        this->distance = distance;
        postorder(root);

        return ans;
    }
};
