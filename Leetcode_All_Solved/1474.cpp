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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur = head;
        bool end = false;
        while(cur != nullptr){
            ListNode* tail;

            for(int i=0;i<m;i++){
                tail = cur; //NOTE

                cur = cur->next;
                if(cur == nullptr){
                    end = true;
                    break;
                }
            }
            if(end) break;

            //ListNode* tail = cur;

            for(int i=0;i<n;i++){
                ListNode* to_del = cur;
                cur = cur->next;

                delete to_del;
                
                if(cur == nullptr){
                    end = true;
                    break;
                }
            }

            //NOTE: including null
            tail->next = cur;
            
            if(end) break;
        }

        return head;
    }
};
