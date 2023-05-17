//m1
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
#include<algorithm>
class Solution {
public:
    inline ListNode* fast_slow_mid(ListNode* head){
        assert(head != nullptr);
        ListNode* slow = head;
        ListNode* fast = head;
        //while(fast != nullptr && fast->next != nullptr){
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //NOTE: for odd count >= 1, the exact middle
        //NOTE: for even count >= 2, the front middle
        return slow;
    }
    inline ListNode* reverse(ListNode* pre, ListNode* cur){
        assert(pre && cur);
        while(cur){
            ListNode* nex = cur->next;
            cur->next = pre;

            pre = cur;
            cur = nex;
        }
        return pre;
    }
    int pairSum(ListNode* head) {
        ListNode* front_mid = fast_slow_mid(head);

        assert(front_mid->next != nullptr);
        ListNode* second = reverse(front_mid, front_mid->next);

        int max_twin = (-1);
        ListNode* first = head;
        do{
            max_twin = max(max_twin, first->val + second->val );
            first = first->next;
            second = second->next;
        }while(second != front_mid);
        return max_twin;
    }
};
