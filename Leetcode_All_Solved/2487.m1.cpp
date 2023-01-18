//m1
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
    ListNode* removeNodes(ListNode* head) {
        if(!head)return nullptr;

        ListNode* nex = removeNodes(head->next);

        if(nex == nullptr)return head;
        if(head->val < nex->val){
            delete head;
            return nex;
        }else{
            head->next = nex;
            return head;
        }
    }
};
