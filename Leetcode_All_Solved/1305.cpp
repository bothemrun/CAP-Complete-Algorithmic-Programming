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
private:
    void inorder(TreeNode* root, vector<int>& sorted){
        if(root == nullptr)return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }
    inline vector<int> merge_sorted(const vector<int>& sorted1, const vector<int>& sorted2){
        vector<int> merged;
        int i = 0, j = 0;
        while(i < sorted1.size() && j < sorted2.size()){
            if(sorted1[i] <= sorted2[j])merged.push_back(sorted1[i++]);
            else merged.push_back(sorted2[j++]);
        }
        
        //1 of 2
        while(i < sorted1.size())merged.push_back(sorted1[i++]);
        while(j < sorted2.size())merged.push_back(sorted2[j++]);
        return merged;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sorted1, sorted2;
        inorder(root1, sorted1);
        inorder(root2, sorted2);
        
        return merge_sorted(sorted1, sorted2);
    }
};
