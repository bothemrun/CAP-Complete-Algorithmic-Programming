/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* preorder(Node* root){
        if(root == nullptr)return nullptr;
        
        Node* root_clone = new Node(root->val);
        for(Node* child: root->children){
            root_clone->children.push_back( preorder(child) );
        }
        
        return root_clone;
    }
    Node* cloneTree(Node* root) {
        return preorder(root);
    }
};
