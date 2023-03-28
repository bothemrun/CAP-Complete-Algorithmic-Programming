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
    int getDecimalValue(ListNode* head) {
        int dec = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            dec = dec*2 + cur->val;
            cur = cur->next;
        }
        return dec;
    }
};
