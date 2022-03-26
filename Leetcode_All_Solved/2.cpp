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
class Solution {
private:
    inline void push_back_new_node(ListNode*& tail, const int& val){
        ListNode* new_node = new ListNode(val);
        tail->next = new_node;
        tail = new_node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode( (l1->val + l2->val)%10 );
        int carry = (l1->val + l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        
        ListNode* tail = head;
        while(l1 != nullptr && l2 != nullptr){
            push_back_new_node(tail, (l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //at most 1 of 2 occurs
        while(l1 != nullptr){
            push_back_new_node(tail, (l1->val + carry)%10);
            carry = (l1->val + carry)/10;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            push_back_new_node(tail, (l2->val + carry)%10);
            carry = (l2->val + carry)/10;
            l2 = l2->next;
        }
        
        //remaining carry
        while(carry > 0){
            push_back_new_node(tail, carry%10);
            carry /= 10;
        }
        
        return head;
    }
};
