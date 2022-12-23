/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
#define test 0 // 1 0
#include<assert.h>
class Solution {
public:
    Node* old_on_right_new_on_left(Node* cur, Node* from_node, Node* topmost_root){
        
        printf("cur %d from_node %d\n", cur->val, ( (from_node==nullptr)? INT_MIN:from_node->val) );

        //NOTE (base case): root stuff
        //just don't forget to adjust topmost root's parent.
        //most importantly, don't forget to cut the original link of root & from_node
        
        if(cur == topmost_root){
            //NOTE: edge case: leaf == root
            if(from_node == nullptr)return topmost_root;//do nothing

            cur->parent = from_node;

            //NOTE: cut original link
            if(cur->left == from_node)
                cur->left = nullptr;
            else if(cur->right == from_node) cur->right = nullptr;
            else assert(false);//NOTE: edge case: leaf == root
            
            #if test == 1
            printf("end: cur %d l %d r %d p %d\n", ( (cur)? cur->val:INT_MIN), ((cur->left)? cur->left->val:INT_MIN), ((cur->right)? cur->right->val:INT_MIN), ((cur->parent)?cur->parent->val:INT_MIN) );
            #endif

            return cur;
        }

        //NOTE (step 1): old on the right
        //so if from_node is from the right, change old left node to the right
        //add the condition "if(cur->right != nullptr)" for the initial leaf
        
        if(cur->right && cur->right == from_node){
            cur->right = cur->left;
        }

        //NOTE (step 2): change cur's parent to from_node, 
        //and remember cur's old parent
        
        Node* cur_old_parent = cur->parent;
        cur->parent = from_node;


        //NOTE (step 3): new append on the left
        //(case 1): from_node is from the right, 
        //and we have moved cur's (old) left node to cur's right,
        //so now append new result of cur's old parent to the left
        //(case 2): from_node -s from the left, 
        //and we didn't change cur's (old) right node,
        //so still now append new result of cur's old parent to the left
        
        cur->left = old_on_right_new_on_left(cur_old_parent, cur, topmost_root);

        //NOTE (step 4): return new append for from_node's recursion

        #if test == 1
        printf("end: cur %d l %d r %d p %d\n", ( (cur)? cur->val:INT_MIN), ((cur->left)? cur->left->val:INT_MIN), ((cur->right)? cur->right->val:INT_MIN), ((cur->parent)?cur->parent->val:INT_MIN) );
        #endif
        
        return cur;
    }

    Node* flipBinaryTree(Node* root, Node * leaf) {
       old_on_right_new_on_left(leaf, nullptr, root); 
       //leaf->parent = nullptr;
       return leaf;
    }
};



