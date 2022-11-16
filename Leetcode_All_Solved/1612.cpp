/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(Node* root, vector<int>& var){
        if(root == nullptr)return;
        if(root->left == nullptr)
            var[(int)(root->val - 'a')]++;
        preorder(root->left, var);
        preorder(root->right, var);
    }
    bool checkEquivalence(Node* root1, Node* root2) {
        vector<int> var1(26, 0);
        vector<int> var2(26, 0);
        preorder(root1, var1);
        preorder(root2, var2);
        
        for(int i=0;i<26;i++)
            if(var1[i] != var2[i])return false;
        return true;
    }
};
