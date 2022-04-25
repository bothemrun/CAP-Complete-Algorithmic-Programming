#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a < b;//max heap
    }
};
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue< int, vector<int>, cmp_class > max_heap;
        for(const int& p:piles)max_heap.push(p);
        
        for(int i=0;i<k;i++){
            int p = max_heap.top();
            max_heap.pop();
            max_heap.push(p-p/2);
        }
        
        int ans = 0;
        while(max_heap.size() != 0){
            ans += max_heap.top();
            max_heap.pop();
        }
        return ans;
    }
};
