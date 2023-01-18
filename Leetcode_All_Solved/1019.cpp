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
    stack<int> monosta;
    vector<int> ans;
    inline int get_len(ListNode* head){
        int cnt = 0;
        while(head != nullptr){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    void next_larger(ListNode* cur, const int& i){
        if(!cur)return;

        next_larger(cur->next, i+1);

        while(monosta.size() != 0 && cur->val >= monosta.top()){
            monosta.pop();
        }

        if(monosta.size() == 0)ans[i] = 0;
        else ans[i] = monosta.top();

        monosta.push(cur->val);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        int n = get_len(head);
        ans.resize(n);
        next_larger(head, 0);
        return ans;
    }
};
