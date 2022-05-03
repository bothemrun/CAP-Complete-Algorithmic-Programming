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
private:
    int k;
    inline bool k_cur_node_get_next_head(ListNode* old_cur_head, ListNode*& next_head){
        if(old_cur_head == nullptr)return false;
        
        int cnt = 0;
        while(old_cur_head != nullptr){
            cnt++;
            if(cnt == k){
                next_head = old_cur_head->next;//may be null
                return true;
            }
            old_cur_head = old_cur_head->next;
        }
        return false;
    }
    inline ListNode* k_reverse(ListNode* old_cur_head){
        ListNode* cur_pre = nullptr;
        ListNode* cur_next;
        int cnt = 0;
        while(old_cur_head != nullptr){
            cur_next = old_cur_head->next;
            old_cur_head->next = cur_pre;
            if(++cnt == k)return old_cur_head;
            //update
            cur_pre = old_cur_head;
            old_cur_head = cur_next;
        }
        return nullptr;//impossible
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        this->k = k;
        ListNode* pre_tail = nullptr;
        ListNode* old_cur_head = head;
        ListNode* next_head;
        ListNode* new_global_head = nullptr;
        while( k_cur_node_get_next_head(old_cur_head, next_head) == true ){
            ListNode* new_cur_head = k_reverse(old_cur_head);
            if(new_global_head == nullptr)new_global_head = new_cur_head;
            if(pre_tail != nullptr)pre_tail->next = new_cur_head;
            old_cur_head->next = next_head;//may be null
            
            //update to next segment
            pre_tail = old_cur_head;
            old_cur_head = next_head;
        }
        return new_global_head;
    }
};
