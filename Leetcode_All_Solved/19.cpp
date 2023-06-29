//1 pass O(n)
//without getting the node count first.

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
#include<assert.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p2 = head;
        for(int i=0;i<n;i++){
            assert(p2);
            p2 = p2->next;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* p1 = head;
        ListNode* p1_pre = dummy;
        while(p2 != nullptr){
            assert(p1);
            p1_pre = p1;
            p1 = p1->next;

            p2 = p2->next;
        }

        assert(p1_pre && p1);
        p1_pre->next = p1->next;
        delete p1;
        
        //edge: size==1
        //return head;
        return dummy->next;
    }
};
