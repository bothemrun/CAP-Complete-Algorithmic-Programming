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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node_am1;
        ListNode* node_bp1;
        ListNode* cur = list1;
        for(int i=0;i<=b+1;i++){
            if(i == a-1) node_am1 = cur;
            else if(i == b+1) node_bp1 = cur;

            cur = cur->next;
        }

        ListNode* list2_tail = list2;
        while(list2_tail->next != nullptr){
            list2_tail = list2_tail->next;
        }
        //NOTE: node_pb1 may be null
        list2_tail->next = node_bp1;

        //NOTE: a == 0
        if(a == 0)return list2;
        
        node_am1->next = list2;
        return list1;
    }
};
