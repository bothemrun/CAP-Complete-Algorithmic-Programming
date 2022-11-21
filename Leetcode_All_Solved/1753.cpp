#include<queue>
class cmp_class{
public:
    bool operator()(const int& s1, const int& s2){
        return s1 < s2;//max heap
    }
};
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int, vector<int>, cmp_class> max_heap;
        vector<int> piles ({a,b,c});
        for(int& p:piles) max_heap.push(p);
        
        int score = 0;
        int nonempty = 3;
        while(nonempty >= 2){
            int p1 = max_heap.top();
            max_heap.pop();
            int p2 = max_heap.top();
            max_heap.pop();
            score++;
            
            if(--p1 == 0)nonempty--;
            else max_heap.push(p1);
            
            if(--p2 == 0)nonempty--;
            else max_heap.push(p2);
        }
        return score;
    }
};
