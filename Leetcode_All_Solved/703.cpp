//NOTE: k heap, not the full n heap, so O(logk) for each operation
#include<queue>
class cmpclass{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//sink down, min heap
    }
};
class KthLargest {
public:
    priority_queue<int, vector<int>, cmpclass> k_minheap;
    int k;
    inline void push_k(const int& val){
        k_minheap.push(val);
        if(k_minheap.size() > k) k_minheap.pop();
    }
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(const int& num: nums) push_k(num);
    }
    
    int add(int val) {
        push_k(val);
        return k_minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
