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
#include<stdlib.h>
class Solution {
public:
    vector<int> pool;
    Solution(ListNode* head) {
        while(head != nullptr){
            pool.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return pool.at( rand()%pool.size() );
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
