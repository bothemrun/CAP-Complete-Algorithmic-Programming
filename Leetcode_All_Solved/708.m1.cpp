//m1
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
#include<assert.h>
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
            if(pre == head) met_head++;

            if(pre->val > cur->val)break;

            pre = cur;
            cur = cur->next;
        }

        Node* front = cur;
        Node* end = pre;
        //NOTE: edge case: <= not < , works for 1 node list
        if(insertVal <= front->val || end->val <= insertVal){
            end->next = new_node;
            new_node->next = front;
            return head;
        }

        assert(head->next != head);//NOTE: not 1 node list
        cur = front;
        while(cur != end && !( cur->val <= insertVal && insertVal <= cur->next->val) ){
            cur = cur->next;
        }

        new_node->next = cur->next;
        cur->next = new_node;
        return head;
    }
};




