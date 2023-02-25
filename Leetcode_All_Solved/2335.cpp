#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a < b;//max heap, sink down
    }
};
class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int, vector<int>, cmp_class> maxheap;
        for(const int& a: amount)if(a != 0) maxheap.push(a);
        int time = 0;
        while(maxheap.size() != 0){
            if(maxheap.size() >= 2){
                int x = maxheap.top();
                maxheap.pop();
                int y = maxheap.top();
                maxheap.pop();
                if(--x > 0) maxheap.push(x);
                if(--y > 0) maxheap.push(y);
                time++;
            }else{
                time += maxheap.top();
                break;
            }
        }

        return time;
    }
};
