//m01
//use hash set for real infinite set,
//but use array set for optim here.
#define max_num (1000+1)
#include<assert.h>
#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap
    }
};
class SmallestInfiniteSet {
public:
    bool fractured_front_inset[max_num] = {0};
    priority_queue<int, vector<int>, cmp_class> fractured_front_minheap;
    int contiguous_head = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(fractured_front_minheap.size() == 0) return contiguous_head++;

        int ret = fractured_front_minheap.top();
        fractured_front_inset[ret] = false;
        fractured_front_minheap.pop();
        return ret;
    }
    
    void addBack(int num) {
        if(num >= contiguous_head || fractured_front_inset[num] == true)return;

        fractured_front_inset[num] = true;
        fractured_front_minheap.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
