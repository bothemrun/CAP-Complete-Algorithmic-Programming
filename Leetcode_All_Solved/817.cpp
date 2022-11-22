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
#include<unordered_set>
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> nums_set;
        for(int& num: nums) nums_set.insert(num);
        
        int components = 0;
        bool pre_in = false;
        while(head != nullptr){
            bool cur_in = (nums_set.count(head->val) != 0);
            if(pre_in == true && cur_in == false)components++;
            
            pre_in = cur_in;
            
            head = head->next;
        }
        
        //NOTE: watch the tail case
        if(pre_in == true)components++;
        
        return components;
    }
};
