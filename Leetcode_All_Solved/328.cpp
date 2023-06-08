//NOTE: Not AC for submission before this on 6/8/2023
//NOTE: they failed because of the test case of [] --> empty list

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
#include<assert.h>
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* heads[2] = {nullptr, nullptr};
        ListNode* tails[2] = {nullptr, nullptr};

        ListNode* cur = head;
        int i=1;
        if(cur == nullptr) return nullptr;
        else{
            heads[1] = cur;
            tails[1] = cur;
            cur = cur->next;
            i++;

            if(cur == nullptr) return head;
            else{
                heads[0] = cur;
                tails[0] = cur;
                cur = cur->next;
                i++;
            }
        }

        //NOTE: use while loop instead of for loop, for the reason below.
        while(cur != nullptr){
            //NOTE: cur->next might be modified(but not in this case), then wrong results for next loop.
            ListNode* cur_next = cur->next;

            assert(tails[i%2] != nullptr);
            tails[i%2]->next = cur;
            tails[i%2] = cur;

            //next loop
            i++;
            cur = cur_next;
        }


        //NOTE: concatenate 2 lists
        assert(tails[1] != nullptr);
        tails[1]->next = heads[0];//ok if null

        //NOTE: final tail
        assert(tails[0] != nullptr);//list size==1, already ruled out
        tails[0]->next = nullptr;

        return heads[1];
    }
};
