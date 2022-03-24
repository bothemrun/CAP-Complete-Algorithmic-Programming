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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr)return nullptr;
        
        ListNode *tail1, *tail2;
        ListNode *head1 = nullptr, *head2 = nullptr;
        for(;head!= nullptr;head = head->next){
            if(head->val < x){
                if(head1 == nullptr){
                    head1 = head;
                    tail1 = head;
                }else{
                    tail1->next = head;
                    tail1 = head;
                }
            }else{
                if(head2 == nullptr){
                    head2 = head;
                    tail2 = head;
                }else{
                    tail2->next = head;
                    tail2 = head;
                }
            }
        }
        
        
        if(head1 != nullptr && head2 != nullptr){
            tail1->next = head2;
            tail2->next = nullptr;
            return head1;
        }else if(head1 != nullptr) return head1;
        else return head2;
    }
};
