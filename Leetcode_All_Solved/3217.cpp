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
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset;
        for(const int& x: nums) uset.insert(x);

        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;

        assert(pre != nullptr);
        ListNode* cur = pre->next;
        assert(cur != nullptr);

        while(cur != nullptr){
            if(uset.find(cur->val) != uset.end()){
                ListNode* next = cur->next; //may be null

                assert(pre != nullptr);
                pre->next = next; //may be null

                delete cur;
                cur = next;
                //pre not changed
            }else{
                pre = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
