#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b; //min heap
    }
};
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, cmp_class> min_heap;
        for(int& stick:sticks)
            min_heap.push(stick);
        
        int cost = 0;
        while(min_heap.size() != 1){
            int a = min_heap.top();
            min_heap.pop();
            int b = min_heap.top();
            min_heap.pop();
            
            min_heap.push(a+b);
            cost += a+b;
        }
        return cost;
    }
};
