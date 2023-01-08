#include<queue>
#include<math.h>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a < b;//max heap
    }
};
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp_class> max_heap;
        for(const int& num: nums){
            max_heap.push(num);
        }
        
        long long score = 0;
        for(int i=0;i<k;i++){
            score += max_heap.top();
            int tmp = max_heap.top();
            max_heap.pop();
            max_heap.push( (int)ceil( ((double)tmp) / 3.0 ) );
        }
        return score;
    }
};
