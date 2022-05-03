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
private:
    inline ListNode* get_middle(ListNode* head, bool& odd){
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast->next == nullptr)odd = true;
        else odd = false;
        return slow;
    }
    inline ListNode* reverse(ListNode* middle_next){
        //size <= 2 excluded, middle_next != null
        ListNode* cur = middle_next;
        ListNode* next;
        ListNode* pre = nullptr;//NOTE: important
        while(cur != nullptr){
            next = cur->next;
            cur->next = pre;
            //update
            pre = cur;
            cur = next;
        }
        return pre;
    }
public:
    void reorderList(ListNode* head) {
        if(head->next == nullptr)return;
        if(head->next->next == nullptr)return;
        
        bool odd;
        ListNode* middle = get_middle(head, odd);
        ListNode* tail = reverse(middle->next);
        
        //merge front & back half
        ListNode* dummy = new ListNode();
        ListNode* append = dummy;
        ListNode* head_next, tail_next;
        while(tail != nullptr){
            append->next = head;
            head_next = head->next;
            head->next = tail;
            //update
            append = tail;
            head = head_next;
            tail = tail->next;
        }
        if(odd){
            append->next = head;
            head->next = nullptr;
        }
        
        head = dummy->next;
    }
};
