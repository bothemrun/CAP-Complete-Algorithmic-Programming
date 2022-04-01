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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* heads[2] = {nullptr, nullptr};
        ListNode* tails[2];
        for(int i=1;head != nullptr;head = head->next, i++){
            if(heads[i%2] == nullptr)heads[i%2] = head;
            else tails[i%2]->next = head;
            tails[i%2] = head;
        }
        
        if(heads[1] != nullptr)tails[1]->next = heads[0];//or nullptr
        if(tails[0] != nullptr)tails[0]->next = nullptr;
        return heads[1];
    }
};
