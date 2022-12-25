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
    vector<int> sorted;
    int m;

    void inorder(TreeNode* root){
        if(root == nullptr)return;
        inorder(root->left);
        sorted.push_back(root->val);
        inorder(root->right);
    }

    inline bool good(const int& i, const int& target){
        if(!(0 <= i))return false;
        return target <= sorted[i];
    }

    int upper(const int& low, const int& high, const int& target){
        int mid = low + (high-low)/2;
        if( good(mid-1, target) == false &&
            good(mid, target) )
            return sorted[mid];
        //NOTE: included low==high

        if(low == high)return (-1);

        if(good(mid, target))
            return upper(low, mid, target);
        else return upper(mid+1, high, target);
    }

    inline bool good2(const int& i, const int& target){
        if(!(i < m))return false;
        return sorted[i] <= target;
    }

    int lower(const int& low, const int& high, const int& target){
        int mid = low + (high-low)/2;
        if( good2(mid, target) &&
            good2(mid+1, target) == false )
            return sorted[mid];
        //NOTE: included low==high

        if(low == high)return (-1);

        if(good2(mid, target))
            return lower(mid+1, high, target);
        else return lower(low, mid, target);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        m = sorted.size();

        int n = queries.size();
        vector<vector<int>> ans(n, vector<int>(2));
        for(int i=0;i<n;i++){
            ans[i][1] = upper(0, m-1, queries[i]);
            ans[i][0] = lower(0, m-1, queries[i]);
        }

        return ans;
    }
};
