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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)return nullptr;
        //get list size
        int n = 0;
        ListNode *tail;
        for(ListNode *cur=head;cur != nullptr;cur = cur->next){
            n++;
            if(cur->next == nullptr)tail = cur;
        }
        
        k %= n;
        if(k == 0)return head;
        k++;
        
        //get reversed head, new tail
        int m = n - k;
        ListNode *new_tail = head;
        for(int i=0;i<m;i++) new_tail = new_tail->next;
        ListNode *new_head = new_tail->next;//won't be null
        new_tail->next = nullptr;
        tail->next = head;
        return new_head;
    }
};
