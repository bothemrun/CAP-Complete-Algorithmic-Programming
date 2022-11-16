/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */
#include<unordered_map>
class Solution {
public:
    unordered_map<Node*, NodeCopy*> old2new;
    unordered_map<Node*, Node*> random_pair;
    unordered_map<NodeCopy*, Node*> new2old;
    NodeCopy* preorder(Node* root){
        if(root == nullptr)return nullptr;
        
        NodeCopy* rootcopy = new NodeCopy(root->val);
        old2new[root] = rootcopy;
        random_pair[root] = root->random;
        new2old[rootcopy] = root;
        
        rootcopy->left = preorder(root->left);
        rootcopy->right = preorder(root->right);
        
        return rootcopy;
    }
    
    void random_preorder(NodeCopy* root){
        if(root == nullptr)return;
        
        root->random = old2new[ random_pair[ new2old[root] ] ];
        
        random_preorder(root->left);
        random_preorder(root->right);
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* rootcopy = preorder(root);
        
        random_preorder(rootcopy);
        return rootcopy;
    }
};
