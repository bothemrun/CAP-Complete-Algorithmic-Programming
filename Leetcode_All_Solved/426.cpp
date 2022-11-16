/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    void inorder(Node* root, Node*& tail){
        if(root == nullptr)return;
        
        inorder(root->left, tail);
        tail->right = root;
        root->left = tail;
        tail = root;
        inorder(root->right, tail);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        inorder(root, tail);
        
        Node* head = dummy->right;
        head->left = tail;
        tail->right = head;
        return head;
    }
};
