#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a < b;//max heap;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, cmp_class> maxheap;
        for(const int& s: stones) maxheap.push(s);

        while(maxheap.size() >= 2){
            int a = maxheap.top();
            maxheap.pop();
            int b = maxheap.top();
            maxheap.pop();
            
            if(a != b) maxheap.push(a-b);
        }

        if(maxheap.size() == 0)return 0;
        else return maxheap.top();
    }
};
