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
        ListNode *cur = head;
        ListNode *pred = nullptr;//init
        bool dup = false;
        while(cur != nullptr){
            while(cur->next != nullptr && cur->val == cur->next->val){
                cur = cur->next;
                dup = true;
            }
            
            if(dup){
                dup = false;
                if(pred == nullptr)head = cur->next;
                else pred->next = cur->next;
                //pred still the same, even same as null
            }else pred = cur;
            cur = cur->next;
        }
        return head;
    }
};
