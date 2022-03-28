/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include<unordered_map>
#include<queue>
class Solution {
private:
    unordered_map<Node*, int> level_m;
    inline void preorder_level(Node* root, int level=0){
        if(root == NULL)return;
        
        this->level_m[root] = level;
        preorder_level(root->left, level+1);
        preorder_level(root->right, level+1);
    }
public:
    Node* connect(Node* root) {
        //get levels
        preorder_level(root);
        
        //level order
        queue<Node*> q;
        if(root == NULL)return root;
        q.push(root);
        int cur_level = 0;
        Node* pre_node = NULL;
        while(q.size() != 0){
            Node* cur_node = q.front();
            q.pop();
            
            if(pre_node == NULL){//pre_node is head
                //do nothing
            }else if(this->level_m[cur_node] == cur_level+1){
                cur_level++;
            }else{//front / middle of level
                pre_node->next = cur_node;
            }
            
            if(cur_node->left != NULL)q.push(cur_node->left);
            if(cur_node->right != NULL)q.push(cur_node->right);
            pre_node = cur_node;
        }
        return root;
    }
};
