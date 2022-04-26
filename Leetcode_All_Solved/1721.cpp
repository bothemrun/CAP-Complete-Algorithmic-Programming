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
    ListNode* kth(ListNode* head, int k){
        for(int i=0;i<k-1;i++)head = head->next;
        return head;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        ListNode* cur = head;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        
        swap( kth(head, k)->val, kth(head, cnt-k+1)->val );
        return head;
    }
};
