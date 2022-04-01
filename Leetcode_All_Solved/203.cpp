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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head;
        while(cur != nullptr && cur->val == val){
            head = cur->next;
            delete cur;
            cur = head;
        }
        
        ListNode *pre;//no null
        while(cur != nullptr){
            if(cur->val == val){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
