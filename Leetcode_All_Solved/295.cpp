#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class maxheap_cmp{
public:
    bool operator()(const int& a, const int& b){
        return a < b;//max heap
    }
};
class minheap_cmp{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap
    }
};

class MedianFinder {
public:
    priority_queue<int, vector<int>, maxheap_cmp> small_heap;
    priority_queue<int, vector<int>, minheap_cmp> big_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small_heap.size() == big_heap.size())
            small_heap.push(num);
        else big_heap.push(num);

        if(big_heap.size() == 0) return;

        if(small_heap.top() > big_heap.top()){
            //swap
            int mismatch = small_heap.top();
            small_heap.pop();

            big_heap.push(mismatch);

            mismatch = big_heap.top();
            big_heap.pop();

            small_heap.push(mismatch);
        }
    }
    
    double findMedian() {
        if(small_heap.size()==big_heap.size())
            return ((double)small_heap.top() + (double)big_heap.top())/2.0;
        else
            return (double)small_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
