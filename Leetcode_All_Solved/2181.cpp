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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        bool first0 = true;
        int sum = 0;
        while(head != nullptr){
            if(head->val == 0){
                if(first0 == true)first0 = false;
                else{
                    cur->next = new ListNode(sum);
                    cur = cur->next;
                    sum = 0;
                }
            }else sum += head->val;
            
            head = head->next;
        }
        return dummy->next;
    }
};
