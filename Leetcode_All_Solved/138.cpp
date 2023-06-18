/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old2copy;

        if(head == nullptr) return nullptr;
        Node* copy_head = new Node(head->val);
        old2copy[head] = copy_head;

        Node *cur = head->next, *copy_tail = copy_head;
        while(cur != nullptr){
            copy_tail->next = new Node(cur->val);
            old2copy[cur] = copy_tail->next;
            
            copy_tail = copy_tail->next;
            cur = cur->next;
        }

        //NOTE: crucial
        copy_tail->next = nullptr;

        cur = head;
        Node* copy_cur = copy_head;
        while(cur != nullptr){
            copy_cur->random = old2copy[ cur->random ];

            cur = cur->next;
            copy_cur = copy_cur->next;
        }

        return copy_head;
    }
};
