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
    string gameResult(ListNode* head) {
        int diff = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            int even = cur->val;
            cur = cur->next;

            assert(cur != nullptr);
            int odd = cur->val;
            cur = cur->next;

            if(even > odd) diff++;
            else diff--;
        }

        if(diff > 0) return "Even";
        else if(diff < 0) return "Odd";
        else return "Tie";
    }
};
