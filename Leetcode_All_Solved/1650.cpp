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
#include<assert.h>
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        //NOTE: same as Two Pointers on 160. Intersection of Two Linked Lists
        //NOTE: assume lengths: a+h, b+h. So (a+h) + b == (b+h) + a
        //NOTE: but if a == b, then might just go (a+h) == (b+h)
        
        Node *a = p, *b = q;
        int redirection_a = 0, redirection_b = 0;
        while(a != b){
            a = a->parent;
            if(a == nullptr){
                a = q;//NOTE
                redirection_a++;
            }
            
            b = b->parent;
            if(b == nullptr){
                b = p;//NOTE
                redirection_b++;
            }
        }
        
        assert(redirection_a <= 1 && redirection_b <= 1);
        return a;
    }
};
