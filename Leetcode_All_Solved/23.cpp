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
#include<queue>
class cmp_class{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;//min heap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp_class > minheap;

        for(ListNode* head: lists)if(head != nullptr)
            minheap.push(head);
        

        ListNode *head = nullptr, *tail = nullptr;
        while(minheap.size() != 0){
            ListNode* next = minheap.top();
            minheap.pop();
            if(next->next != nullptr) minheap.push(next->next);

            if(head == nullptr){
                head = next;
                tail = next;
            }else{
                tail->next = next;
                tail = next;
            }
        }

        return head;
    }
};
