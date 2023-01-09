/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* new_node = new Node(insertVal);

        if(head == nullptr){
            new_node->next = new_node;
            return new_node;
        }

        Node* cur = head->next;
        Node* pre = head;
        int met_head = 0;
        while(met_head <= 1){
            //NOTE: edge case 1
            if(pre == head)met_head++;

            //NOTE: general case
            if(pre->val <= insertVal && insertVal <= cur->val)
                break;
            
            //NOTE: edge case 2
            if(pre->val > cur->val){
                if(pre->val <= insertVal || insertVal <= cur->val)
                break;
            }

            pre = cur;
            cur = cur->next;
        }

        pre->next = new_node;
        new_node->next = cur;

        return head;
    }
};


