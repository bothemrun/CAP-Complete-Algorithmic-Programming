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
#define no_critical (-1)
#include<algorithm>
#include<limits.h>
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first_critical = no_critical;
        int last_critical = no_critical;
        int min_d = INT_MAX;
        int max_d = INT_MIN;

        ListNode* cur = head, *pre = nullptr;
        int i = 0;
        while(cur != nullptr){
            if(cur == head || cur->next == nullptr){
                i++;
                pre = cur;
                cur = cur->next;
                continue;
            }

            if( (pre->val < cur->val && cur->next->val < cur->val) ||
                (pre->val > cur->val && cur->next->val > cur->val) 
            ){

                if(first_critical == no_critical){
                    first_critical = i;
                }else{
                    min_d = min(min_d, i - last_critical);
                    max_d = max(max_d, i - first_critical);
                }

                last_critical = i;
            }

            
            i++;
            pre = cur;
            cur = cur->next;
        }

        if(first_critical == no_critical || first_critical == last_critical)
            return vector<int>({-1, -1});
        else return vector<int>({min_d, max_d});
    }
};
