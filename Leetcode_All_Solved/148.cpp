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
//m0
//merge sort. fast slow pointers to find the middle.
//O(nlogn) time, O(1) space
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(head1 != nullptr && head2 != nullptr){
            assert(tail != nullptr);
            if(head1->val < head2->val){
                tail->next = head1;
                tail = tail->next;
                
                head1 = head1->next;
            }else{
                tail->next = head2;
                tail = tail->next;

                head2 = head2->next;
            }
        }

        //ok if both null
        if(head1 != nullptr) tail->next = head1;
        if(head2 != nullptr) tail->next = head2;
        
        return dummy->next;
    }

    ListNode* fast_slow_find_mid_left(ListNode* head){
        assert(head!=nullptr);
        ListNode *slow = head, *fast = head;
        
        assert(fast != nullptr);
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge_sort(ListNode* head){
        if(head==nullptr) return nullptr;

        //NOTE: crucial termination: list of 1 node
        if(head->next == nullptr) return head;

        //ok for list of 1 node
        ListNode* mid = fast_slow_find_mid_left(head);

        assert(mid!=nullptr);
        //NOTE: head2 may be null since odd list of size 1
        ListNode* head2 = mid->next;

        ListNode* head1 = head;
        //NOTE: make an independent list for the left part
        assert(mid!=nullptr);
        mid->next = nullptr;

        head1 = merge_sort(head1);
        head2 = merge_sort(head2);

        return merge(head1, head2);
    }
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};
