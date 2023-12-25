#include<assert.h>
#include<queue>

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        auto cmp = [](const int& a, const int& b){
            return a>b;//min heap
        };
        priority_queue<int, vector<int>, decltype(cmp) > minheap(cmp);
        
        for(const int& x: nums) minheap.push(x);

        vector<int> arr;
        while(minheap.size()){
            int alice = minheap.top();
            minheap.pop();

            assert(minheap.size());
            int bob = minheap.top();
            minheap.pop();

            arr.push_back(bob);
            arr.push_back(alice);
        }

        return arr;
    }
};
