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
    ListNode* deleteMiddle(ListNode* head) {
        //NOTE: slow fast pointers
        ListNode *slow = head, *fast = head;
        ListNode *pre_slow = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            pre_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(pre_slow != nullptr){
            pre_slow->next = slow->next;
            delete slow;
        }else return nullptr;
        return head;
    }
};
