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
    ListNode *neg_head = nullptr, *neg_tail = nullptr;
    ListNode *pos_head;
    inline void push_neg_front(ListNode* cur){
        if(neg_head == nullptr){
            cur->next = nullptr;
            neg_head = cur;
            neg_tail = cur;
        }else{
            cur->next = neg_head;
            neg_head = cur;
        }
    }

    inline void pop_pos(ListNode* pre, ListNode* next){
        if(pre != nullptr) pre->next = next;
        else pos_head = next;      
    }

    ListNode* sortLinkedList(ListNode* head) {
        pos_head = head;

        ListNode *cur = head;
        ListNode *pre = nullptr;
        while(cur != nullptr){
            ListNode* next = cur->next;

            if(cur->val < 0){
                push_neg_front(cur);

                pop_pos(pre, next);
                //NOTE: not update pre
            }else{
                pre = cur;
            }

            cur = next;
        }

        if(neg_tail != nullptr){
            neg_tail->next = pos_head;//may be null
            return neg_head;
        }else return head;
    }
};
