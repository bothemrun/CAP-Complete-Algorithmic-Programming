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
#include<algorithm>
class Solution {
public:
    inline void push_front(ListNode*& head, const int& val){
        ListNode* new_node = new ListNode(val);

        if(head == nullptr) head = new_node;
        else{
            new_node->next = head;
            head = new_node;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        for(ListNode* cur=l1;cur!=nullptr;cur=cur->next)
            v1.push_back(cur->val);
        for(ListNode* cur=l2;cur!=nullptr;cur=cur->next)
            v2.push_back(cur->val);
        

        int len1 = v1.size();
        int len2 = v2.size();

        ListNode* head = nullptr;
        int carry = 0;
        //merge 2 sorted list
        for(int i=0;i<min(len1, len2);i++){
            int val = v1[len1-1 - i] + v2[len2-1 - i] + carry;
            
            carry = val / 10;
            val %= 10;

            push_front(head, val);
        }

        for(int i=min(len1, len2);i<len1;i++){
            int val = v1[len1-1 - i] + carry;

            carry = val / 10;
            val %= 10;

            push_front(head, val);
        }

        for(int i=min(len1, len2);i<len2;i++){
            int val = v2[len2-1 - i] + carry;

            carry = val / 10;
            val %= 10;

            push_front(head, val);
        }


        //NOTE: edge:
        if(carry != 0) push_front(head, carry);


        return head;
    }
};
