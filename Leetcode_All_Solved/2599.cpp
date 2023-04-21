#include<assert.h>
#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap, sink down
    }
};
class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        priority_queue<int, vector<int>, cmp_class> minheap;
        int op = 0;
        long long prefix_sum = 0;
        for(const int& num: nums){
            if(num < 0) minheap.push(num);

            prefix_sum += num;
            if(prefix_sum < 0){
                prefix_sum -= minheap.top();
                minheap.pop();
                op++;

                assert(prefix_sum >= 0);
            }
        }
        return op;
    }
};
