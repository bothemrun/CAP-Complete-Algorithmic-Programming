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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> cnt;
        
        ListNode* cur = head;
        while(cur != nullptr){
            cnt[cur->val]++;
            cur = cur->next;
        }

        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        for(const auto& [key, val]: cnt){
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next;
    }
};
