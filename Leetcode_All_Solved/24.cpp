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
    ListNode* swapPairs(ListNode* head) {        
        if(head == nullptr)return nullptr;
        if(head->next == nullptr)return head;
        
        ListNode *leftleft = nullptr;
        ListNode *p1 = head, *p2 = head->next;
        
        head = head->next;
        
        while(p2 != nullptr){
            //NOTE: p1, p2 != null here
            ListNode *rightright = p2->next;
            if(leftleft != nullptr) leftleft->next = p2;
            p2->next = p1;
            
            leftleft = p1;
            
            if(rightright == nullptr){//0 left
                p1->next = nullptr;
                break;
            }
            if(rightright->next == nullptr){//1 left
                p1->next = rightright;
                break;
            }
            //2 or more left
            p1 = rightright;
            p2 = rightright->next;
        }
        return head;
    }
};
