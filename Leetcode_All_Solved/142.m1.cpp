//m1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    inline ListNode* get_cycle(ListNode* head){
        ListNode *slow = head, *fast = head;
        bool started = false;
        while(fast->next != nullptr && fast->next->next != nullptr){
            if(started == true && fast == slow)return slow;
            if(started == false)started = true;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        return nullptr;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)return nullptr;
        
        ListNode* met = get_cycle(head);
        if(met == nullptr)return nullptr;
        
        //2k - k == n*(cycle size) == k
        while(head != met){
            head = head->next;
            met = met->next;
        }
        return head;
    }
};
