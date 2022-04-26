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
#include<algorithm>
class Solution {
private:
    inline ListNode* slow_fast_middle(ListNode* head){
        //NOTE: leetcode 876 middle of the linked list
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next == nullptr)return slow;//not used here
        else return slow->next;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* middle = slow_fast_middle(head);
        //reverse 2nd half
        ListNode* pre = nullptr;//don't care
        ListNode* cur = middle;
        ListNode* tail;
        while(cur != nullptr){
            if(cur->next == nullptr)tail = cur;
            
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        //sum twins
        int max_twin = 0;
        ListNode *first = head, *second = tail;
        while(true){
            max_twin = max(max_twin, first->val + second->val);
            if(second == middle)break;
            first = first->next;
            second = second->next;
        }
        return max_twin;
    }
};
