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
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int recur_carry(ListNode* cur){
        if(cur == nullptr) return 0;

        cur->val *= 2;
        cur->val += recur_carry(cur->next);

        int carry = cur->val / 10;
        cur->val %= 10;
        return carry;
    }
    ListNode* doubleIt(ListNode* head) {
        //edge case for leading 0
        if(head->next == nullptr && head->val == 0) return head;

        int carry = recur_carry(head);

        if(carry != 0){
            assert(carry <= 9);
            ListNode* cur = new ListNode(carry);
            cur->next = head;
            head = cur;
        }
        return head;
    }
};
