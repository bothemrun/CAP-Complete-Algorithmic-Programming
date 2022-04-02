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
#include<stack>
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> s;
        ListNode *cur = head;
        ListNode *left_head;//in case left end is just the head
        ListNode *leftleft = nullptr;//NOTE: in case left end is just the head
        for(int i=1;cur != nullptr;i++){
            if(i == left - 1){
                leftleft = cur;//NOTE: or already just null
                //cur = cur->next;//TODO
            }else if(left <= i && i < right){
                s.push(cur);
                //cur = cur->next;//TODO
            }else if(i == right){
                s.push(cur);
                if(leftleft == nullptr)left_head = cur;//NOTE: in case left end is jsut the head
                ListNode *rightright = cur->next;//NOTE
                ListNode *rev_pre = leftleft;//NOTE: might be null
                while(s.size() != 0){
                    ListNode *n = s.top();
                    s.pop();
                    
                    if(rev_pre != nullptr)rev_pre->next = n;//NOTE: in case left end is just the head
                    rev_pre = n;
                }//while
                rev_pre->next = rightright;//NOTE: can be rightright / or just null
                cur = rightright;//NOTE: lastly reversed is in front of window now
                continue;
            }
            
            cur = cur->next;
        }//for i
        
        if(leftleft == nullptr)return left_head;
        else return head;
    }
};
