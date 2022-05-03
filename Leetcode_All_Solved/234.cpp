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
    inline ListNode* get_middle(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    inline ListNode* reverse_2nd_half(ListNode* middle_next){
        ListNode* cur = middle_next;
        ListNode* pre = nullptr;//NOTE: important
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            //update
            pre = cur;
            cur = next;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr)return true;
        
        ListNode* middle = get_middle(head);
        ListNode* tail = reverse_2nd_half(middle->next);
        while(tail != nullptr){//NOTE: where important helps!
            if(head->val != tail->val)return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};
