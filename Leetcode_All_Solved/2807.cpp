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
    int gcd(const int& a, const int& b){
        //a >= b
        if(a%b == 0) return b;
        return gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        assert(cur);
        while(cur->next != nullptr){
            ListNode* next = cur->next;

            assert(next);
            ListNode* g = new ListNode( gcd(cur->val, next->val) );
            cur->next = g;
            g->next = next;

            cur = next;
        }

        return head;
    }
};
