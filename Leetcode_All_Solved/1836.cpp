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
#include<unordered_map>
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int> times;
        ListNode* cur = head;
        while(cur != nullptr){
            if(times.count(cur->val) != 0) times[cur->val]++;
            else times[cur->val] = 1;
            
            cur = cur->next;
        }
        
        cur = head;
        ListNode* prev = nullptr;
        while(cur != nullptr){
            bool del_cur = false;
            if(times[cur->val] != 1){
                if(prev != nullptr) prev->next = cur->next;//may be null
                
                del_cur = true;
                
                if(cur == head) head = cur->next;
            }
            
            if(del_cur == false) prev = cur;
            //else: not update prev
            
            ListNode* to_del_cur = cur;
            cur = cur->next;
            //if(del_cur) delete cur;//memory leak
            //NOTE: maybe test program will use it: if(del_cur) delete to_del_cur;//memory leak, heap-use-after-free...
        }
        return head;
    }
};
