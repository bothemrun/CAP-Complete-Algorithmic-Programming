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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        ListNode* head = list;
        
        int cnt = 1;
        ListNode* tail = head;
        while(tail->next != head){
            tail = tail->next;
            cnt++;
        }

        int back1_cnt = ( (cnt%2==0)? (cnt/2):(cnt/2+1) );
        ListNode* back1 = head;
        for(int i=1;i<back1_cnt;i++){
            back1 = back1->next;
        }

        ListNode* front2 = back1->next;
        assert(front2 != head);

        back1->next = head;
        tail->next = front2;
        return vector<ListNode*>({head, front2});
    }
};
