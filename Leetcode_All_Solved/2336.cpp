//NOTE: unlimited num & real infinite set, also better time than first push 1~1000 to heap.
#include<queue>
#include<unordered_set>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap
    }
};
class SmallestInfiniteSet {
public:
    //NOTE: poppedAddBack: 
    //NOTE: (1) mostly be incontiguous, while the normal unused numbers always contiguous 
    //NOTE: (2) always smaller than (in front of) the normal unused numbers
    
    int normal_contiguous_unused_smallest = 1;
    priority_queue<int, vector<int>, cmp_class> fracture_poppedAddBack_min_heap;
    unordered_set<int> fracture_poppedAddBack_set;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(fracture_poppedAddBack_min_heap.size() == 0){
            normal_contiguous_unused_smallest++;
            return normal_contiguous_unused_smallest - 1;
        }else{
            int smallest = fracture_poppedAddBack_min_heap.top();
            fracture_poppedAddBack_min_heap.pop();
            fracture_poppedAddBack_set.erase(smallest);
            return smallest;
        }
    }
    
    void addBack(int num) {
        if(num < normal_contiguous_unused_smallest && fracture_poppedAddBack_set.count(num) == 0){
            fracture_poppedAddBack_min_heap.push(num);
            fracture_poppedAddBack_set.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
