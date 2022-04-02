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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode *pre = cur;
            while(cur->next != nullptr && cur->val == cur->next->val) cur = cur->next;
            pre->next = cur->next;//ok for null
            cur = cur->next;
        }
        return head;
    }
};
