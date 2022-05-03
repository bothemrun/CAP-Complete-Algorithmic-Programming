/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool started = false;
        while(fast != nullptr && fast->next != nullptr){
            if(slow == fast && started == true)return true;
            if(started == false)started = true;
            //NOTE: speed difference == 1, so ?*1 must reach slow from behind
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
