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
    inline int ll_size(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = ll_size(head);
        
        vector<ListNode*> ans;
        for(int i=0;i<k;i++){
            ans.push_back(head);
            
            int part_cnt = n/k + ((i<n%k)?1:0);//NOTE: conditional/ternary operator
            if(part_cnt > 0){
                for(int j=0;j<part_cnt-1;j++)head = head->next;
                //head at last node of this part
                ListNode* next = head->next;
                head->next = nullptr;
                head = next;
            }
        }
        return ans;
    }
};
