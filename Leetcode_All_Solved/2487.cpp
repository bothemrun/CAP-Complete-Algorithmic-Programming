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
    ListNode* removeNodes(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;
        while(cur != nullptr){
            arr.push_back(cur->val);
            cur = cur->next;
        }

        int n = arr.size();
        stack<int> monosta;
        vector<bool> keep(n);
        for(int i=n-1;i>=0;i--){
            while(monosta.size() != 0 && arr[i] >= monosta.top()){
                monosta.pop();
            }

            keep[i] = monosta.size() == 0;

            monosta.push(arr[i]);
        }

        int i = 0;
        cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            if(keep[i] == false){
                if(pre == nullptr){
                    head = cur->next;
                }else{
                    pre->next = cur->next;
                }

                //pre the same
                ListNode* del = cur;
                cur = cur->next;
                delete del;
            }else{
                pre = cur;
                cur = cur->next;
            }

            i++;
        }

        return head;
    }
};
