/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<stack>
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> sta;
        ListNode* cur = head;
        while(cur != nullptr){
            sta.push(cur);
            cur = cur->next;
        }
        (sta.top()->val)++;
        
        int carry = 0;
        while(sta.size() != 0){
            cur = sta.top();
            sta.pop();
            
            cur->val += carry;
            carry = cur->val / 10;
            cur->val %= 10;
            
            if(carry == 0)break;
        }
        
        //if(head->val / 10 != 0){
        if(carry != 0){
            ListNode* new_head = new ListNode(carry);
            new_head->next = head;
            head = new_head;
        }
        return head;
    }
};
