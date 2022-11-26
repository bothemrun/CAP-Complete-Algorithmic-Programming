/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<assert.h>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //NOTE: same as 1650 Lowest Common Ancestor of a Binary Tree III
        //NOTE: assume lengths:a+h, b+h. then (a+h)+b == (b+h)+a
        //NOTE: but maybe a == b, so already (a+h)==(b+h)
        ListNode *a = headA, *b = headB;
        int redirection_a = 0, redirection_b = 0;
        while(a != b){
            a = a->next;
            if(a == nullptr){
                a = headB;
                if(++redirection_a >= 2)return nullptr;
            }
            
            b = b->next;
            if(b == nullptr){
                b = headA;
                if(++redirection_b >= 2)return nullptr;
            }
        }
        
        assert(redirection_a <= 1 && redirection_b <= 1);
        return a;
    }
};
