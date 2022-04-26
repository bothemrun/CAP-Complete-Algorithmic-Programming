/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* inorder(Node* head){
        if(!head)return nullptr;
        
        Node* cur = head;
        Node* next = head->next;
        
        cur->next = inorder(cur->child);
        if(cur->next)cur->next->prev = cur;
        cur->child = nullptr;
        
        while(cur->next)cur = cur->next;//(1)if has child, to tail of flattened child list (2)if not, do nothing --> prev of old next in flattened list
        
        cur->next = inorder(next);
        if(next) cur->next->prev = cur;
        
        return head;
    }
public:
    Node* flatten(Node* head) {
        return inorder(head);
    }
};
