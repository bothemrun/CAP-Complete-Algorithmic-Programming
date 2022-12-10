#include<queue>
#include<unordered_set>
#include<assert.h>
class cmp_class{
public:
    bool operator()(const long long& a, const long long& b){
        return a > b;//min heap, true then first item sinks down
    }
};
class Solution {
public:
    priority_queue<long long, vector<long long>, cmp_class> min_heap;
    unordered_set<long long> in_heap;

    inline void push(const long long& x){
        if(in_heap.count(x) == 0){
            min_heap.push(x);
            in_heap.insert(x);
        }
    }
    inline void pop(){
        assert(min_heap.size() != 0);
        long long x = min_heap.top();
        min_heap.pop();
        in_heap.erase(x);
    }

    int nthUglyNumber(int n) {
        push(1);

        long long x;
        for(int i=1;i<=n;i++){
            x = min_heap.top();
            pop();

            push(x*2);
            push(x*3);
            push(x*5);
        }
        return x;
    }
};
